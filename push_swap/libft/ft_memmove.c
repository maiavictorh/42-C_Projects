/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:18:42 by victode-          #+#    #+#             */
/*   Updated: 2025/12/26 16:12:58 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
