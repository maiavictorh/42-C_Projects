/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:41:12 by victode-          #+#    #+#             */
/*   Updated: 2026/10/29 20:30:48 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int ac, char **av)
{
	int			data[9];
	t_manager	*manager;

	if (!validate_args(ac, av, data))
		exit(EXIT_FAILURE);
	manager = init_manager(data);
	clear_manager(manager);
	return (0);
}
