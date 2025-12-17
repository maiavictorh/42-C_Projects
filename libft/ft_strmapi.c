/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:07:26 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:05:37 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Creates a new string by the applying the function 'f' to each
 * 		  character of the string 's'.
 * 
 * @param s The string to be used.
 * @param f The function to be applied in each character.
 * @return The string created by the successive applications of the 'f' function.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
char	next_char(unsigned int i, char c)
{
	(void)i;
	return c + 1;
}

int main(void)
{
	char *result = ft_strmapi("abc", next_char);
	ft_printf("ft_strmapi: 'abc' -> '%s' (should be 'bcd')\n", result);
	free(result);
}
*/