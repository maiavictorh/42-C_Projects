/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:25:38 by victode-          #+#    #+#             */
/*   Updated: 2026/10/22 18:19:16 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	init_manager(int *data)
{
	t_manager	*manager;

	manager = (t_manager *)malloc(sizeof(t_manager));
	manager->num_coders = data[0];
	manager->time_to_burnout = data[1];
	manager->time_to_compile = data[2];
	manager->time_to_debug = data[3];
	manager->time_to_refactor = data[4];
	manager->compiles_required = data[5];
	manager->dongle_cooldown = data[6];
	manager->scheduler = data[7];
}

t_dongle	*init_dongles(t_manager manager)
{
	int			i;
	t_dongle	*dongle;
	t_dongle	*dongles;

	i = 0;
	while (i < manager.num_coders)
	{
		dongle = (t_dongle *)malloc(sizeof(t_dongle));
		dongle->id = i + 1;
		dongle->cooldown = manager.dongle_cooldown;
		dongles[i] = *dongle;
	}
	return (dongles);
}

t_coder	*init_coders(int num_coders)
{
	int		i;
	t_coder	*coder;
	t_coder	*coders;

	i = 0;
	while (i < num_coders)
	{
		coder = (t_coder *)malloc(sizeof(t_coder));
		coder->id = i + 1;
	}
}
