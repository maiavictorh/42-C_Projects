/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:37:27 by victode-          #+#    #+#             */
/*   Updated: 2026/11/09 23:40:23 by victode-         ###   ########.fr       */
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
		return (pthread_mutex_unlock(&manager->heap_mutex), 0);
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

int	get_best_request(t_manager *manager)
{
	int		i;
	int		best;
	long	current_time;

	i = 0;
	best = -1;
	current_time = get_current_time(manager);
	if (current_time < 0)
		return (-1);
	while (i < manager->heap.size)
	{
		if (is_dongle_available(&manager->heap.requests[i], current_time))
		{
			if (best == -1)
				best = i;
			else if (compare_requests(manager->scheduler,
					&manager->heap.requests[i],
					&manager->heap.requests[best]) < 0)
				best = i;
		}
		i++;
	}
	return (best);
}

void	scheduler(t_manager *manager)
{
	int			best;
	t_request	request;

	while (manager->running)
	{
		pthread_mutex_lock(&manager->heap_mutex);
		best = get_best_request(manager);
		if (best != -1)
		{
			heap_remove(manager->scheduler, &manager->heap, best, &request);
			request.coder->left_dongle->in_use = 1;
			request.coder->right_dongle->in_use = 1;
			request.coder->request_status = RS_GRANTED;
			pthread_cond_broadcast(&manager->scheduler_cond);
		}
		else
			pthread_cond_wait(&manager->scheduler_cond, &manager->heap_mutex);
		pthread_mutex_unlock(&manager->heap_mutex);
	}
}
