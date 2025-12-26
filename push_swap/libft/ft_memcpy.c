/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:11:27 by victode-          #+#    #+#             */
/*   Updated: 2025/12/26 16:25:41 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src_ptr;
	char		*dst_ptr;

	i = -1;
	src_ptr = (const char *)src;
	dst_ptr = (char *)dest;
	if (!dst_ptr && !src_ptr)
		return (NULL);
	while (++i < n)
		dst_ptr[i] = src_ptr[i];
	return (dest);
}
