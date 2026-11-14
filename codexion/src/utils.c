/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 01:29:42 by victode-          #+#    #+#             */
/*   Updated: 2026/11/13 21:18:55 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	clear_manager(t_manager *manager)
{
	if (!manager)
		return ;
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

long	get_elapsed_time(t_manager *manager)
{
	long	time;

	time = get_time();
	if (time < 0)
		return (-1);
	return (time - manager->start_time);
}

void	log_message(t_coder *coder, char *message)
{
	pthread_mutex_lock(&coder->manager->mutex);
	if (coder->manager->running)
	{
		printf("%ld %d %s\n", get_elapsed_time(coder->manager),
		coder->id, message);
	}
	pthread_mutex_unlock(&coder->manager->mutex);
}

int	is_running(t_manager *manager)
{
	int	running;

	pthread_mutex_lock(&manager->mutex);
	running = manager->running;
	pthread_mutex_unlock(&manager->mutex);
	return (running);
}
