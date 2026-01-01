/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:31:50 by victode-          #+#    #+#             */
/*   Updated: 2026/01/01 18:49:46 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_verif_overflow(char digit, int num, int sign)
{
	t_ll	n;

	n = num;
	if ((sign == 1 && n > ((INT_MAX - (digit - '0')) / 10))
		|| (sign == -1 && n > (-(t_ll)INT_MIN - (digit - '0')) / 10))
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
int	main(void)
{
	ft_printf("%d\n", ft_atoi("-2147483648asdf"));
}
 */