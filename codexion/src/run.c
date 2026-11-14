/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:54:10 by victode-          #+#    #+#             */
/*   Updated: 2026/11/13 21:42:27 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	*monitor_routine(void *arg)
{
	int			i;
	int			burned_id;
	long		current_time;
	long		burnout_time;
	t_manager	*manager;

	manager = (t_manager *)arg;
	while (manager->running)
	{
		i = 0;
		burned_id = 0;
		pthread_mutex_lock(&manager->mutex);
		current_time = get_time();
		while (i < manager->num_coders)
		{
			if (current_time - manager->coders[i].last_compile_start
				>= manager->time_to_burnout)
				{
					manager->running = 0;
					burned_id = manager->coders[i].id;
					burnout_time = get_elapsed_time(manager);
					break ;
				}
			i++;
		}
		pthread_mutex_unlock(&manager->mutex);
		if (burned_id)
		{
			printf("%ld %d burned out\n", burnout_time, burned_id);
			return (manager->running = 0, NULL);
		}
	}
	return (NULL);
}

int	run(t_manager *manager)
{
	int	i;
	
	if (pthread_create(&manager->monitor, NULL, monitor_routine, manager))
		return (1);
	i = 0;
	while (i < manager->num_coders)
	{
		if (pthread_create(&manager->coders[i].thread, NULL,
			coder_routine, &manager->coders[i]))
			return (1);
		i++;
	}
	return (0);
}
