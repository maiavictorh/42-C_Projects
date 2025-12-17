/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:26:53 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:06:12 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Converts a lowercase letter to uppercase.
 *
 * @param c Character to convert.
 * @return The uppercase equivalent if c is lowercase, otherwise c unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
int main(void)
{
	char c = 'c';

	ft_printf("%c = %c\n", c, ft_toupper(c));
}
*/