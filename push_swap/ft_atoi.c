/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:01:22 by victode-          #+#    #+#             */
/*   Updated: 2026/01/02 21:16:27 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_numbers(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && !ft_isdigit(*s))
			s++;
		if (*s && ft_isdigit(*s))
			count++;
		while (*s && ft_isdigit(*s))
			s++;
	}
	return (count);
}

int	ft_verif_overflow(char digit, int num, int sign)
{
	t_ull	n;

	n = num;
	if (((sign == 1 && n > ((INT_MAX - (*digit - '0')) / 10))
			|| (sign == -1 && n > (-(t_ll)INT_MIN - (digit - '0')) / 10)))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
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
		ft_error();
	while (ft_isdigit(*nptr))
	{
		if (ft_verif_overflow(*nptr, num, sign))
			ft_error();
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr != '\0')
		ft_error();
	return (sign * num);
}
/*
int main(void)
{
	printf("%d\n", ft_atoi("2147483648"));
}
*/