/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:18:42 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:04:50 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copies n bytes from src to dst, even if the regions overlap.
 *
 * @param dest Destination memory area.
 * @param src Source memory area.
 * @param n Number of bytes to copy.
 * @return A pointer to dst.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src_ptr;
	char		*dst_ptr;

	src_ptr = (const char *)src;
	dst_ptr = (char *)dest;
	if (src < dest)
	{
		i = n;
		while (i--)
			dst_ptr[i] = src_ptr[i];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
int main(void)
{
	char s[] = "Howdy World!";

	// Normal case:
	ft_printf("Before: %s;\n", s);
	ft_memmove(s, "Hello", 5);
	ft_printf("Result: %s;\n", s);

	char s2[] = "abcdefgh";

	// Overlapping left:
	ft_printf("Before: %s;\n", s2);
	ft_memmove(s2, s2 + 2, 5);
	ft_printf("Result: %s;\n", s2);

	char s3[] = "ABCDEFGH";

	// Overlapping right:
	ft_printf("Before: %s;\n", s3);
	ft_memmove(s3 + 2, s3, 5);
	ft_printf("Result: %s;\n", s3);
}
*/