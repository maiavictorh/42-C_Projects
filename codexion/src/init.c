/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:25:38 by victode-          #+#    #+#             */
/*   Updated: 2026/11/04 17:44:57 by victode-         ###   ########.fr       */
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
		if (pthread_mutex_init(&manager->dongles[i].mutex, NULL))
		{
			while (i > 0)
				pthread_mutex_destroy(&manager->dongles[--i].mutex);
			free(manager->dongles);
			return (manager->dongles = NULL, 0);
		}
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
		manager->coders[i].data = manager;
		manager->coders[i].request_status = RS_IDLE;
		i++;
	}
	return (1);
}

static int	init_scheduler(t_manager *manager)
{
	manager->scheduler_cond_flag = 0;
	manager->heap_mutex_flag = 0;
	manager->heap.size = 0;
	manager->heap.capacity = manager->num_coders;
	manager->heap.requests = malloc(sizeof(t_request) * manager->heap.capacity);
	if (!manager->heap.requests)
		return (0);
	if (pthread_mutex_init(&manager->heap_mutex, NULL))
		return (0);
	manager->heap_mutex_flag = 1;
	if (pthread_cond_init(&manager->scheduler_cond, NULL))
		return (0);
	manager->scheduler_cond_flag = 1;
	return (1);
}

t_manager	*init_manager(int *data)
{
	t_manager	*manager;

	manager = malloc(sizeof(t_manager));
	if (!manager)
		return (NULL);
	manager->dongles = NULL;
	manager->coders = NULL;
	manager->heap.requests = NULL;
	manager->heap.size = 0;
	manager->heap.capacity = 0;
	manager->num_coders = data[0];
	manager->time_to_burnout = data[1];
	manager->time_to_compile = data[2];
	manager->time_to_debug = data[3];
	manager->time_to_refactor = data[4];
	manager->compiles_required = data[5];
	manager->dongle_cooldown = data[6];
	manager->scheduler = data[7];
	if (!init_dongles(manager))
		return (clear_manager(manager), NULL);
	if (!init_coders(manager))
		return (clear_manager(manager), NULL);
	if (!init_scheduler(manager))
		return (clear_manager(manager), NULL);
	return (manager);
}
