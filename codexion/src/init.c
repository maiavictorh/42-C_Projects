/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:25:38 by victode-          #+#    #+#             */
/*   Updated: 2026/10/24 13:20:53 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static t_dongle	*init_dongles(t_manager *manager)
{
	int			i;
	t_dongle	*dongles;

	i = 0;
	dongles = malloc(sizeof(t_dongle) * manager->num_coders);
	if (!dongles)
		return (NULL);
	while (i < manager->num_coders)
	{
		dongles[i].id = i + 1;
		dongles[i].cooldown = manager->dongle_cooldown;
		i++;
	}
	return (dongles);
}

static t_coder	*init_coders(t_manager *manager)
{
	int		i;
	t_coder	*coders;

	i = 0;
	coders = malloc(sizeof(t_coder) * manager->num_coders);
	if (!coders)
		return (NULL);
	while (i < manager->num_coders)
	{
		coders[i].id = i + 1;
		coders[i].compiles_done = 0;
		coders[i].last_compile_start = 0;
		coders[i].last_dongle_release = 0;
		coders[i].left_dongle = &manager->dongles[i];
		if (i == manager->num_coders - 1)
			coders[i].right_dongle = &manager->dongles[0];
		else
			coders[i].right_dongle = &manager->dongles[i + 1];
		coders[i].data = manager;
		i++;
	}
	for (int i = 0; i < manager->num_coders; i++)
		printf("Coder%d: Dongle%d - Dongle%d\n", \
			coders[i].id, coders[i].left_dongle->id, coders[i].right_dongle->id);
	return (coders);
}

t_manager	*init_manager(int *data)
{
	t_manager	*manager;

	manager = malloc(sizeof(t_manager));
	if (!manager)
		return (NULL);
	manager->dongles = NULL;
	manager->coders = NULL;
	manager->num_coders = data[0];
	manager->time_to_burnout = data[1];
	manager->time_to_compile = data[2];
	manager->time_to_debug = data[3];
	manager->time_to_refactor = data[4];
	manager->compiles_required = data[5];
	manager->dongle_cooldown = data[6];
	manager->scheduler = data[7];
	manager->dongles = init_dongles(manager);
	if (!manager->dongles)
		return (clear_manager(manager), NULL);
	manager->coders = init_coders(manager);
	if (!manager->coders)
		return (clear_manager(manager), NULL);
	return (manager);
}
