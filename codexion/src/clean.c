/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:20:20 by victode-          #+#    #+#             */
/*   Updated: 2026/11/20 13:18:43 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	clear_manager(t_manager *manager)
{
	if (!manager)
		return ;
	pthread_mutex_destroy(&manager->mutex);
	free(manager->heap.requests);
	free(manager->coders);
	free(manager->dongles);
	free(manager);
}

void	abort_run(t_manager *manager, int created)
{
	int	i;

	pthread_mutex_lock(&manager->mutex);
	manager->running = 0;
	pthread_mutex_unlock(&manager->mutex);
	pthread_join(manager->monitor, NULL);
	i = 0;
	while (i < created)
		pthread_join(manager->coders[i++].thread, NULL);
}
