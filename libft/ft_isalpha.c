/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:02:09 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 13:59:48 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks if a character is alphabetic (A–Z or a–z).
 *
 * @param c Character to check.
 * @return Non-zero if c is alphabetic, zero otherwise.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
int	main(void)
{
	char c = 'a';
	ft_printf("Result: %d;\n", ft_isalpha(c));
}
*/