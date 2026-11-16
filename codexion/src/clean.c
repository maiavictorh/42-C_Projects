/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:20:20 by victode-          #+#    #+#             */
/*   Updated: 2026/11/16 17:57:24 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	clear_manager(t_manager *manager)
{
	if (!manager)
		return ;
	pthread_mutex_destroy(&manager->mutex);
	pthread_cond_destroy(&manager->cond);
	free(manager->heap.requests);
	free(manager->coders);
	free(manager->dongles);
	free(manager);
}

void	abort_run(t_manager *manager, int created);
