/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:01:22 by victode-          #+#    #+#             */
/*   Updated: 2026/09/22 14:30:29 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	validate_number(const char *s, int *result)
{
	int		i;
	long	num;

	if (!strlen(s))
		return (0);
	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		if (num > (INT_MAX - (s[i] - '0')) / 10)
			return (0);
		num = num * 10 + (s[i] - '0');
		i++;
	}
	*result = (int)num;
	return (1);
}

int	validate_args(int ac, char **av)
{
	int	i;
	int	res;

	if (ac != 9)
		return (write(2, "ERROR: wrong number of args!\n", 30), 0);
	i = 1;
	while (i < ac)
	{
		if (i < 8)
		{
			if (!validate_number(av[i++], &res))
				return (write(2, "ERROR: Invalid arg!\n", 21), 0);
		}
		else
		{
			if (!strcmp(av[i], "fifo") || !strcmp(av[i], "edf"))
				i++;
			else
			{
				write(2, "ERROR: scheduler must be 'fifo' or 'edf'\n", 41);
				return (0);
			}
		}
	}
	return (1);
}
