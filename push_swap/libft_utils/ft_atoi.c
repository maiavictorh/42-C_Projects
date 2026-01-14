/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:01:22 by victode-          #+#    #+#             */
/*   Updated: 2026/01/14 18:07:04 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_numbers(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
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
		if (s[i] && !ft_isspace(s[i]))
			return (0);
	}
	return (count);
}

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
/*
int main(void)
{
	char *s = "  -123";
	int result;
	
	printf("%d\n", ft_count_numbers(s));
	if (ft_atoi(s, &result) == 1)
    	printf("Número: %d\n", result);  // -123
	else
    	printf("Erro na conversão\n");
}
*/