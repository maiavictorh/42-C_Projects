/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 01:29:42 by victode-          #+#    #+#             */
/*   Updated: 2026/11/04 16:59:15 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	clear_manager(t_manager *manager)
{
	if (!manager)
		return ;
	if (!manager->scheduler_cond_flag)
		pthread_cond_destroy(&manager->scheduler_cond);
	if (!manager->heap_mutex_flag)
		pthread_mutex_destroy(&manager->heap_mutex);
	free(manager->heap.requests);
	free(manager->coders);
	free(manager->dongles);
	free(manager);
}
