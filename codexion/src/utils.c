/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 01:29:42 by victode-          #+#    #+#             */
/*   Updated: 2026/10/23 02:02:15 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	clear_manager(t_manager *manager)
{
	if (!manager)
		return ;
	free(manager->coders);
	free(manager->dongles);
	free(manager);
}
