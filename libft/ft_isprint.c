/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:37:37 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:04:20 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks if a character is printable (including space).
 *
 * @param c Character to check.
 * @return Non-zero if c is printable, zero otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int	main(void)
{
	char c = '~';
	ft_printf("Result: %d;\n", ft_isprint(c));
}
*/