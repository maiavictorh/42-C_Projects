/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:54:10 by victode-          #+#    #+#             */
/*   Updated: 2026/11/16 18:20:27 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static void	get_burnout(t_manager *manager, int *id, long *burnout_time)
{
	int		i;
	long	current_time;

	i = 0;
	pthread_mutex_lock(&manager->mutex);
	current_time = get_time();
	while (i < manager->num_coders)
	{
		if (current_time - manager->coders[i].last_compile_start
			>= manager->time_to_burnout)
		{
			manager->running = 0;
			*id = manager->coders[i].id;
			*burnout_time = get_elapsed_time(manager);
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&manager->mutex);
}

static int	create_coders_threads(t_manager *manager)
{
	int		i;

	i = 0;
	while (i < manager->num_coders)
	{
		if (pthread_create(&manager->coders[i].thread, NULL,
				coder_routine, &manager->coders[i]))
		{
			abort_run(manager, i);
			break ;
		}
		i++;
	}
	return (1);
}

void	*monitor_routine(void *arg)
{
	int			burn_id;
	long		burn_time;
	t_manager	*manager;

	manager = (t_manager *)arg;
	while (manager->running)
	{
		burn_id = 0;
		get_burnout(manager, &burn_id, &burn_time);
		if (burn_id)
			return (printf("%ld %d burned out\n", burn_time, burn_id), NULL);
	}
	return (NULL);
}

int	run(t_manager *manager)
{
	int	i;

	manager->start_time = get_time();
	if (pthread_create(&manager->monitor, NULL, monitor_routine, manager))
		return (0);
	if (!create_coders_threads(manager))
		return (0);
	i = 0;
	while (i < manager->num_coders)
		pthread_join(manager->coders[i++].thread, NULL);
	pthread_join(manager->monitor, NULL);
	return (1);
}
