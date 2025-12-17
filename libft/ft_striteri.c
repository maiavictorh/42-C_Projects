/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:12:11 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:05:16 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Applies the function 'f' to each character of the string 's'
 * 
 * @param s The string to be used
 * @param f The function to be applied in each character
 * @return The result of the successive applications of the 'f' function
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	test_toupper(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

int main(void)
{
	char s[] = "hello world!";

	ft_printf("Before: %s\n", s);
	ft_striteri(s, test_toupper);
	ft_printf("Result: %s\n", s);
}
*/