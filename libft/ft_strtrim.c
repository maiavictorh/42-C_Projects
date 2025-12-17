/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:22:44 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:06:03 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Erases the 'set' characters from the start and the end of the string.
 * 
 * @param s1 String to be trimmed.
 * @param set Characters to erase.
 * @return A string result of the trim.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!set)
		return ((char *)s1);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
/* int main(void)
{
	char *s = "----Hello World++++";
	char *set = "-";

	ft_printf("Before: %s;\n", s);
	char *res = ft_strtrim(s, set);
	ft_printf("Result: %s;\n", res);
}
 */