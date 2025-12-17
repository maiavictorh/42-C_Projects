/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:27:03 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:05:46 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * @param s The string to search in.
 * @param c The character to locate (interpreted as unsigned char).
 * @return A pointer to the last occurrence of c, or NULL if not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int main(void)
{
	const char *s = "Hello World!";

	ft_printf("Result: %s;\n", ft_strrchr(s, 'o'));
}
*/