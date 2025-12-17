/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:35:03 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 13:59:36 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks if a character is an ASCII character (0–127).
 *
 * @param c Character to check.
 * @return Non-zero if c is ASCII, zero otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
	char c = '~';
	ft_printf("Result: %d;\n", ft_isascii(c));
}
*/