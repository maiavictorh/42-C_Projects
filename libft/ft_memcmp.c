/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:37:17 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:04:36 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Compares two memory blocks byte by byte.
 *
 * @param s1 Pointer to the first memory block.
 * @param s2 Pointer to the second memory block.
 * @param n Number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if s1 is found
 *         to be less than, to match, or be greater than s2, respectively.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*p1;
	const char	*p2;

	i = 0;
	p1 = (const char *)s1;
	p2 = (const char *)s2;
	if (n == 0)
		return (0);
	while (p1[i] == p2[i] && i < n - 1)
		i++;
	return ((unsigned char)p1[i] - (unsigned char)p2[i]);
}
/*
int main(void)
{
	char *s1 = "Hello world!";
	char *s2 = "Hello World!";

	ft_printf("Result: %d;\n", ft_memcmp(s1, s2, 7));
}
*/