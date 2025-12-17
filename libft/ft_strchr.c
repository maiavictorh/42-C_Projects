/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:00:31 by victode-          #+#    #+#             */
/*   Updated: 2025/12/03 22:14:30 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * @param s The string to search in.
 * @param c The character to locate.
 * @return A pointer to the first occurrence of c, or NULL if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int main(void)
{
	const char *s = "Hello World!";

	ft_printf("Result: %s;\n", ft_strchr(s, 'o'));
}
*/