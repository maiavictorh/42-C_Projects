/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:47:38 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:05:33 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Calculates the length of a null-terminated string.
 *
 * @param s Pointer to the string.
 * @return The number of characters in the string, excluding the null terminator.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int main(void)
{
	const char *s = "Hello World!";

	ft_printf("Result: %lu;\n", ft_strlen(s));
}
*/