/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:37:27 by victode-          #+#    #+#             */
/*   Updated: 2026/11/09 00:20:42 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

int	create_request(t_coder *coder)
{
	long		current_time;
	t_request	request;
	t_manager	*manager;

	manager = coder->data;
	pthread_mutex_lock(&manager->heap_mutex);
	if (coder->request_status != RS_IDLE)
		return (0);
	current_time = get_current_time(manager);
	if (current_time < 0)
		return (pthread_mutex_unlock(&manager->heap_mutex), 0);
	request.coder = coder;
	request.request_time = current_time;
	request.deadline = coder->last_compile_start + manager->time_to_burnout;
	request.sequence = manager->sequence++;
	if (!heap_insert(manager->scheduler, &manager->heap, &request))
		return (pthread_mutex_unlock(&manager->heap_mutex), 0);
	coder->request_status = RS_WAITING;
	pthread_cond_signal(&manager->scheduler_cond);
	pthread_mutex_unlock(&manager->heap_mutex);
	return (1);
}

int	wait_for_grant(t_coder *coder)
{
	t_manager	*manager;

	manager = coder->data;
	pthread_mutex_lock(&manager->heap_mutex);
	while (coder->request_status != RS_GRANTED)
		pthread_cond_wait(&manager->scheduler_cond, &manager->heap_mutex);
	pthread_mutex_unlock(&manager->heap_mutex);
	return (1);
}

int	is_dongle_available(t_request *request, long current_time)
{
	t_dongle	*left;
	t_dongle	*right;

	left = request->coder->left_dongle;
	right = request->coder->right_dongle;
	return (!left->in_use && !right->in_use
		&& left->available_at < current_time
		&& right->available_at < current_time);
}

void	scheduler(t_manager *manager);
