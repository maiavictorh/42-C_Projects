/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:05:26 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 13:56:02 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Sets all bytes in a block of memory to zero.
 *
 * @param s Pointer to the memory area.
 * @param n Number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int main(void)
{
	char s[] = "Hello World!";
	
	ft_bzero(s, 4);
	ft_printf("Result: ");
	for (size_t i = 0; i < 4; i++)
		ft_printf("%x", s[i]);
	for (size_t i = 0; i < 13; i++)
		ft_printf("%c", s[i]);
	ft_printf("\n");
}
 */