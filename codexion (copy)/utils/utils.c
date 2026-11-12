/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 01:29:42 by victode-          #+#    #+#             */
/*   Updated: 2026/11/09 14:47:08 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	clear_manager(t_manager *manager)
{
	if (!manager)
		return ;
	if (!manager->scheduler_cond_flag)
		pthread_cond_destroy(&manager->scheduler_cond);
	if (!manager->heap_mutex_flag)
		pthread_mutex_destroy(&manager->heap_mutex);
	free(manager->heap.requests);
	free(manager->coders);
	free(manager->dongles);
	free(manager);
}

long	get_time(void)
{
	struct timespec	ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts))
		return (-1);
	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

long	get_current_time(t_manager *manager)
{
	long	time;

	time = get_time();
	if (time < 0)
		return (-1);
	return (time - manager->start_time);
}
