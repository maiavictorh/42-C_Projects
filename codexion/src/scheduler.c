/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:37:27 by victode-          #+#    #+#             */
/*   Updated: 2026/11/06 00:42:17 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

int	create_request(t_coder *coder, t_manager *manager)
{
	long		current_time;
	t_request	request;

	pthread_mutex_lock(&manager->heap_mutex);
	current_time = get_current_time(manager);
	if (current_time < 0)
		return (pthread_mutex_unlock(&manager->heap_mutex), 0);
	request.coder = coder;
	request.request_time = current_time;
	request.deadline = coder->last_compile_start + manager->time_to_burnout;
	request.sequence = manager->sequence++;
	heap_insert(manager->scheduler, &manager->heap, &request);
	coder->request_status = RS_WAITING;
	pthread_cond_signal(&manager->scheduler_cond);
	pthread_mutex_unlock(&manager->heap_mutex);
	return (1);
}

void	scheduler(t_manager *manager);
