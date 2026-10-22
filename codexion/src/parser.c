/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:01:22 by victode-          #+#    #+#             */
/*   Updated: 2026/10/22 18:20:06 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static int	validate_number(const char *s, int *result)
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

static int	set_scheduler(char *arg, int *scheduler)
{
	if (!strcmp(arg, "fifo"))
		*scheduler = FIFO;
	else if (!strcmp(arg, "edf"))
		*scheduler = EDF;
	else
		return (write(2, "ERROR: scheduler must be 'fifo' or 'edf'\n", 41), 0);
	return (1);
}

int	validate_args(int ac, char **av, int *data)
{
	int	i;
	int	j;

	if (ac != 9)
		return (write(2, "ERROR: wrong number of arguments!\n", 35), 0);
	i = 1;
	j = 0;
	while (i < 8)
	{
		if (!validate_number(av[i++], &data[j++]))
			return (write(2, "ERROR: Invalid argument!\n", 26), 0);
	}
	if (!set_scheduler(av[i], &data[j]))
		return (0);
	return (1);
}
