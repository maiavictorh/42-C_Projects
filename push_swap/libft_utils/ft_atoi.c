/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:01:22 by victode-          #+#    #+#             */
/*   Updated: 2026/01/15 17:58:49 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	verif_overflow(char digit, int num, int sign)
{
	t_ll	n;

	n = num;
	if (((sign == 1 && n > ((INT_MAX - (digit - '0')) / 10))
			|| (sign == -1 && n > (-(t_ll)INT_MIN - (digit - '0')) / 10)))
		return (1);
	return (0);
}

int	ft_atoi(char *nptr, int *result)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (0);
	while (ft_isdigit(*nptr))
	{
		if (verif_overflow(*nptr, num, sign))
			return (0);
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr != '\0')
		return (0);
	return (*result = sign * num, 1);
}
