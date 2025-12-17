/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:20:20 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:04:33 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Searches for a specific byte in a memory block.
 *
 * @param s Pointer to the memory area.
 * @param c The byte value to search for (interpreted as unsigned char).
 * @param n Number of bytes to examine.
 * @return A pointer to the first occurrence of c, or NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			p;
	const char		*ptr;

	i = 0;
	p = (unsigned char)c;
	ptr = (const char *)s;
	while (i < n)
	{
		if (ptr[i] == p)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	const char *s = "Hello World!";

	ft_printf("Result: %s;\n", (char *)ft_memchr(s, 'W', 7));
}
*/