/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:01:48 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:04:24 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Calculates the length of an integer (Equivalent to a string).
 *
 * @param n The integer to be converted.
 * @return The number of characters the integer may have.
 */
static size_t	ft_numblen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/**
 * @brief Converts an integer to a newly allocated string representation.
 *
 * @param n The integer to convert.
 * @return A pointer to the newly allocated string representing the integer.
 *         Returns NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*res;

	nb = n;
	len = ft_numblen(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	res[len] = '\0';
	while (len-- > 0 && res[len] != '-')
	{
		res[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
/*
int main(void)
{
	char *s = ft_itoa(-2147483647);

	ft_printf("Result: %s\n", s);
	ft_printf("Decimal: ");
	for (size_t i = 0; i < ft_strlen(s) + 1; i++)
		ft_printf("%d ", s[i]);
	ft_printf("\n");
}
*/