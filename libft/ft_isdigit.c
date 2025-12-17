/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:21:57 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:04:12 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks if a character is a decimal digit (0–9).
 *
 * @param c Character to check.
 * @return Non-zero if c is a digit, zero otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int	main(void)
{
	char c = '7';
	ft_printf("Result: %d;\n", ft_isdigit(c));
}
*/