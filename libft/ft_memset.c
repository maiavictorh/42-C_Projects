/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:52:48 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:04:54 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Fills a block of memory with a specific byte value.
 * 
 * @param s Pointer to the memory area to fill.
 * @param c The value to be set (interpreted as unsigned char).
 * @param n Number of bytes to set.
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
		ptr[i++] = c;
	return (s);
}
/*
int main(void)
{
	char s[] = "Hello World!";
	ft_printf("Result: %s;\n", (char *)ft_memset(s, '-', 4));
}
*/