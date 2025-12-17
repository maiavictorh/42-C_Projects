/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:16:49 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:06:06 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Create a substring started by the index 'start'.
 * 
 * @param s String to be used.
 * @param start Index where the subtring starts.
 * @param len Length the substring should have.
 * @return The substring with a '\0' in the end.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
/*
int main(void)
{
	char *s = "Hello World!";
	char *sub = ft_substr(s, 6, ft_strlen(s));

	ft_printf("Original: %s;\nSubstring: %s;\n", s, sub);
}
*/