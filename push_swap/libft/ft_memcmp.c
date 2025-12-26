/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:37:17 by victode-          #+#    #+#             */
/*   Updated: 2025/12/26 16:22:28 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return ((t_uc)p1[i] - (t_uc)p2[i]);
}
