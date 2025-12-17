/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:35:21 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:05:29 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copies a string from src to dst with size limitation.
 *
 * @param dst Destination buffer.
 * @param src Source string.
 * @param size Maximum size of the destination buffer.
 * @return The total length of the string it tried to create (length of src).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
int main(void)
{
	char dst[20] = "Howdy World!";
	const char *src = "Hello World!";

	size_t result = ft_strlcpy(dst, src, 6);
	ft_printf("Src: %s\n", src);
	ft_printf("Dst: %s\n", dst);
	ft_printf("Return: %zu\n", result);
	return 0;
}
*/