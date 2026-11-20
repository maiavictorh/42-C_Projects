/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:23:06 by victode-          #+#    #+#             */
/*   Updated: 2026/11/20 14:17:46 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static int	get_dongles(t_coder *coder, t_manager *manager)
{
	int	best;

	pthread_mutex_lock(&manager->mutex);
	if (!create_request(coder))
		return (pthread_mutex_unlock(&manager->mutex), 0);
	while (1)
	{
		if (!manager->running)
			return (pthread_mutex_unlock(&manager->mutex), 0);
		best = get_best_request(manager);
		if (best != -1 && manager->heap.requests[best].coder == coder)
			break ;
		pthread_mutex_unlock(&manager->mutex);
		usleep(200);
		pthread_mutex_lock(&manager->mutex);
	}
	heap_remove(manager->scheduler, &manager->heap, best);
	coder->left_dongle->in_use = 1;
	coder->right_dongle->in_use = 1;
	coder->last_compile_start = get_elapsed_time(manager);
	pthread_mutex_unlock(&manager->mutex);
	log_message(coder, "has taken a dongle");
	log_message(coder, "has taken a dongle");
	return (1);
}

int	compile(t_coder *coder)
{
	long		current_time;
	t_manager	*manager;

	manager = coder->manager;
	if (!get_dongles(coder, manager))
		return (0);
	log_message(coder, "is compiling");
	usleep(manager->time_to_compile * 1000);
	pthread_mutex_lock(&manager->mutex);
	coder->left_dongle->in_use = 0;
	coder->right_dongle->in_use = 0;
	current_time = get_elapsed_time(manager);
	coder->left_dongle->available_at = current_time + manager->dongle_cooldown;
	coder->right_dongle->available_at = current_time + manager->dongle_cooldown;
	coder->compiles_done++;
	pthread_mutex_unlock(&manager->mutex);
	return (is_running(manager));
}

int	debug(t_coder *coder)
{
	log_message(coder, "is debugging");
	usleep(coder->manager->time_to_debug * 1000);
	return (is_running(coder->manager));
}

int	refactor(t_coder *coder)
{
	log_message(coder, "is refactoring");
	usleep(coder->manager->time_to_refactor * 1000);
	return (is_running(coder->manager));
}

void	*coder_routine(void *arg)
{
	t_coder		*coder;

	coder = (t_coder *)arg;
	if (coder->manager->num_coders == 1)
		return (log_message(coder, "has taken a dongle"), NULL);
	while (is_running(coder->manager))
	{
		if (!compile(coder))
			break ;
		if (!debug(coder))
			break ;
		if (!refactor(coder))
			break ;
	}
	return (NULL);
}
