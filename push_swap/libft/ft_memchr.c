/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:20:20 by victode-          #+#    #+#             */
/*   Updated: 2025/12/26 16:23:26 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			p;
	const char		*ptr;

	i = 0;
	p = (t_uc)c;
	ptr = (const char *)s;
	while (i < n)
	{
		if (ptr[i] == p)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}
