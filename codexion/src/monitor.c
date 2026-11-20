/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:55:37 by victode-          #+#    #+#             */
/*   Updated: 2026/11/20 13:25:08 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static int	all_done(t_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->num_coders)
	{
		if (manager->coders[i++].compiles_done < manager->compiles_required)
			return (0);
	}
	return (1);
}

static int	check_burnout(t_manager *manager, int *id, long *burnout_time)
{
	int		i;
	long	current_time;

	i = 0;
	current_time = get_elapsed_time(manager);
	while (i < manager->num_coders)
	{
		if (current_time - manager->coders[i].last_compile_start
			>= manager->time_to_burnout)
		{
			manager->running = 0;
			*id = manager->coders[i].id;
			*burnout_time = current_time;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_end(t_manager *manager)
{
	int		burn_id;
	long	burn_time;

	if (!manager->running)
		return (1);
	if (all_done(manager))
		return (manager->running = 0, 1);
	burn_id = 0;
	if (check_burnout(manager, &burn_id, &burn_time))
		return (printf("%ld %d burned out\n", burn_time, burn_id), 1);
	return (0);
}

void	*monitor_routine(void *arg)
{
	int			end;
	t_manager	*manager;

	manager = (t_manager *)arg;
	while (1)
	{
		pthread_mutex_lock(&manager->mutex);
		end = check_end(manager);
		pthread_mutex_unlock(&manager->mutex);
		if (end)
			break ;
		usleep(1000);
	}
	return (NULL);
}
