/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:41:12 by victode-          #+#    #+#             */
/*   Updated: 2026/09/18 16:07:40 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	parse_args(int ac, char **av)
{
	int	i;

	if (ac != 9)
		return (write(2, "ERROR: Not enough args!\n", 24), 0);
	i = 1;
	while (i < ac)
	{
		if (i < 8)
		{
			if (!validate_number(av[i++]))
				return (write(2, "ERROR: Invalid arg!\n", 20), 0);
		}
		else
		{
			if (strlen(av[i])!strcmp(av[i], "fifo") || !strcmp(av[i], "edf"))
				continue;
			else
				return (write(2, "ERROR: scheduler must be 'fifo' or 'edf'\n", 41), 0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (!parse_args(ac, av))
		exit(EXIT_FAILURE);
}
