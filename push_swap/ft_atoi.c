/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:01:22 by victode-          #+#    #+#             */
/*   Updated: 2026/01/03 22:24:59 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_numbers(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r')))
			i++;
		if (s[i] == '+' || s[i] == '-')
		{
			if (!ft_isdigit(s[++i]))
				return (0);
		}
		if (s[i] && ft_isdigit(s[i]))
			count++;
		while (s[i] && ft_isdigit(s[i]))
			i++;
	}
	return (count);
}

static int	ft_verif_overflow(char digit, int num, int sign)
{
	t_ll	n;

	n = num;
	if (((sign == 1 && n > ((INT_MAX - (digit - '0')) / 10))
			|| (sign == -1 && n > (-(t_ll)INT_MIN - (digit - '0')) / 10)))
		return (1);
	return (0);
}

int	ft_atoi(char *nptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
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