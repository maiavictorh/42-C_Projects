/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:01:48 by victode-          #+#    #+#             */
/*   Updated: 2025/12/26 16:11:37 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numblen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*res;

	nb = n;
	len = ft_numblen(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	res[len] = '\0';
	while (len-- > 0 && res[len] != '-')
	{
		res[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
