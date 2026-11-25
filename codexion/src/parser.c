/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:01:22 by victode-          #+#    #+#             */
/*   Updated: 2026/11/25 01:05:28 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

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
	{
		printf("\33[31mERROR: scheduler must be 'fifo' or 'edf'\n\33[0m");
		return (0);
	}
	return (1);
}

int	validate_args(int ac, char **av, int *data)
{
	int	i;
	int	j;

	if (ac != 9)
		return (printf("\33[31mERROR: wrong number of arguments!\n\33[0m"), 0);
	i = 1;
	j = 0;
	while (i < 8)
	{
		if (!validate_number(av[i++], &data[j++]))
			return (printf("\33[31mERROR: Invalid argument!\n\33[0m"), 0);
	}
	if (!set_scheduler(av[i], &data[j]))
		return (0);
	return (1);
}
