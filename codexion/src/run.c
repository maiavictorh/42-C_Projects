/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:54:10 by victode-          #+#    #+#             */
/*   Updated: 2026/11/17 14:56:03 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static int	create_coders_threads(t_manager *manager)
{
	int		i;

	i = 0;
	while (i < manager->num_coders)
	{
		if (pthread_create(&manager->coders[i].thread, NULL,
				coder_routine, &manager->coders[i]))
			return (abort_run(manager, i), 0);
		i++;
	}
	return (1);
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
