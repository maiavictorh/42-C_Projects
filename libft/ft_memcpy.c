/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:11:27 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:04:43 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copies n bytes from src to dst (not safe for overlapping regions).
 *
 * @param dest Destination memory area.
 * @param src Source memory area.
 * @param n Number of bytes to copy.
 * @return A pointer to dst.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src_ptr;
	char		*dst_ptr;

	i = 0;
	src_ptr = (const char *)src;
	dst_ptr = (char *)dest;
	if (!dst_ptr && !src_ptr)
		return (NULL);
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
	char src[] = "Hello World!";
	char dst[] = "Howdy people of the world!";
	
	ft_printf("Before: %s\n", dst);
	char *res = ft_memcpy(dst, src, 6);
	ft_printf("Result: %s\n", res);
}
*/