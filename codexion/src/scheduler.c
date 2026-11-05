/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:37:27 by victode-          #+#    #+#             */
/*   Updated: 2026/11/05 19:26:44 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	create_request(t_coder *coder, t_manager *manager)
{
	pthread_mutex_lock(manager->heap_mutex);
}

void	scheduler(t_manager *manager);
