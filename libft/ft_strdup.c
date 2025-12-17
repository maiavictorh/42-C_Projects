/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:08:19 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:05:12 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Duplicates a string by allocating new memory for a copy.
 *
 * @param s The string to duplicate.
 * @return A pointer to the newly allocated copy of s1, or NULL if
 * 		   allocation fails.
 */
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	dup = (char *)malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(void)
{
	char *src = "Hello, World!!!";
	char *dest = ft_strdup(src);

	if (!dest)
	{
		ft_printf("Strdup failed!");
		return (1);
	}
	ft_printf("Original string: %s;\n", src);
	ft_printf("Copied string: %s;\n", dest);
	free(dest);
}
*/