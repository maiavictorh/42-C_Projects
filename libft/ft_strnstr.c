/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:27:09 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:05:43 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Locates a substring within a string, limited by length.
 *
 * @param big The main string to search in.
 * @param little The substring to find.
 * @param len Maximum number of characters to search.
 * @return A pointer to the beginning of the located substring,
 * 		   or NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		j = 0;
		while ((i + j) < len && little[j] && little[j] == big[i + j])
			j++;
		if (little[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char *big = "Hello people of the world!";
	char *little = "of";
	char *result = ft_strnstr(big, little, 15);
	ft_printf("Big: %s;\nLittle: %s;\nResult: %s;\n", big, little, result);
}
*/