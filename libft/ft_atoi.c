/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:44:06 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 13:56:38 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Converts a string to an integer.
 *
 * @param nptr The string representing the number.
 * @return The converted integer value.
 */
int	ft_atoi(const char *nptr)
{
	int		num;
	int		sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * num);
}
/* 
int main(void)
{
	char *s = "\t\r\f\v   -1234abcde567";

	ft_printf("Result: %d;\n", ft_atoi(s));
}
 */