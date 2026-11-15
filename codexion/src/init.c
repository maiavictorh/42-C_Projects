/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:25:38 by victode-          #+#    #+#             */
/*   Updated: 2026/11/15 01:11:23 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

static int	init_dongles(t_manager *manager)
{
	int	i;

	i = 0;
	manager->dongles = malloc(sizeof(t_dongle) * manager->num_coders);
	if (!manager->dongles)
		return (0);
	while (i < manager->num_coders)
	{
		manager->dongles[i].id = i + 1;
		manager->dongles[i].cooldown = manager->dongle_cooldown;
		manager->dongles[i].in_use = 0;
		manager->dongles[i].available_at = 0;
		i++;
	}
	return (1);
}

static int	init_coders(t_manager *manager)
{
	int		i;

	i = 0;
	manager->coders = malloc(sizeof(t_coder) * manager->num_coders);
	if (!manager->coders)
		return (0);
	while (i < manager->num_coders)
	{
		manager->coders[i].id = i + 1;
		manager->coders[i].compiles_done = 0;
		manager->coders[i].last_compile_start = 0;
		manager->coders[i].last_dongle_release = 0;
		manager->coders[i].left_dongle = &manager->dongles[i];
		if (i == manager->num_coders - 1)
			manager->coders[i].right_dongle = &manager->dongles[0];
		else
			manager->coders[i].right_dongle = &manager->dongles[i + 1];
		manager->coders[i].manager = manager;
		manager->coders[i].request_status = RS_IDLE;
		i++;
	}
	return (1);
}

static int	store_data(t_manager *manager, int *data)
{
	manager->dongles = NULL;
	manager->coders = NULL;
	manager->heap.requests = NULL;
	manager->heap.size = 0;
	manager->heap.capacity = 0;
	manager->num_coders = data[0];
	if (manager->num_coders  < 1)
		return (0);
	manager->time_to_burnout = data[1];
	manager->time_to_compile = data[2];
	manager->time_to_debug = data[3];
	manager->time_to_refactor = data[4];
	manager->compiles_required = data[5];
	manager->dongle_cooldown = data[6];
	manager->scheduler = data[7];
	return (1);
}

t_manager	*init_manager(int *data)
{
	t_manager	*manager;
	
	manager = malloc(sizeof(t_manager));
	if (!manager)
		return (NULL);
	if (!store_data(manager, ))
		return (clear_manager(manager), NULL);
	if (!init_dongles(manager))
		return (clear_manager(manager), NULL);
	if (!init_coders(manager))
		return (clear_manager(manager), NULL);
	if (pthread_mutex_init(&manager->mutex, NULL))
		return (clear_manager(manager), NULL);
	if (pthread_cond_init(&manager->cond, NULL))
		return (clear_manager(manager));
	manager->sequence = 0;
	manager->start_time = get_time();
	manager->running = 1;
	manager->heap.size = 0;
	manager->heap.capacity = manager->num_coders;
	manager->heap.requests = malloc(sizeof(t_request) * manager->heap.capacity);
	if (!manager->heap.requests)
		return (clear_manager(manager), NULL);
	return (manager);
}
