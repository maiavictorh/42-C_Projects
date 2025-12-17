/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:44:10 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:06:09 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Converts an uppercase letter to lowercase.
 *
 * @param c Character to convert.
 * @return The lowercase equivalent if c is uppercase, otherwise c unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
int main(void)
{
	char c = 'C';

	ft_printf("%c = %c\n", c, ft_tolower(c));
}
*/