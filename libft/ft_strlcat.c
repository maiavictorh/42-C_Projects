/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:53:30 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:05:25 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Concatenates src to dst ensuring null termination and size safety.
 *
 * @param dst Destination buffer (must be null-terminated).
 * @param src Source string to append.
 * @param size Total size of the destination buffer.
 * @return The total length of the string it tried to create (dst + src length).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	if (size > 0)
	{
		i = dst_len;
		j = 0;
		while (src[j] && j < size - dst_len - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (dst_len + src_len);
}
/*
int main(void)
{
	char dst[20] = "Hello ";
	const char *src = "World";

	ft_printf("Src: %s\n", src);
	ft_printf("Dst: %s\n", dst);
	size_t result = ft_strlcat(dst, src, sizeof(dst));    
	ft_printf("Result: %s\n", dst);
	ft_printf("Return: %zu\n", result);
	return 0;
}
*/