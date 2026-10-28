/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:11:51 by victode-          #+#    #+#             */
/*   Updated: 2026/10/28 17:52:20 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	manager_routine(t_manager *manager)
{
	int	i;

	if (pthread_create(manager->monitor, NULL, monitor_routine, arg))
		return (clear_manager(manager));
	i = 0;
	while (i < manager->num_coders)
	{
		if (pthread_create(manager->coders[i].thread))
			return (clear_manager(manager));
		i++;
	}
}
