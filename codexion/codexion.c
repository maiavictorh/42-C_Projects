/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:41:12 by victode-          #+#    #+#             */
/*   Updated: 2026/11/14 19:05:47 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int ac, char **av)
{
	int			data[9];
	t_manager	*manager;

	if (!validate_args(ac, av, data))
		return (1);
	manager = init_manager(data);
	if (manager == NULL)
		return (1);
	// run(manager);
	clear_manager(manager);
	return (0);
}
