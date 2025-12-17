/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:02:59 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:15:51 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A newly allocated string containing the concatenation of s1 and s2,
 *         or NULL if memory allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	t_ull	i;
	t_ull	j;
	char	*join;

	i = 0;
	j = 0;
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}
/* 
int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *join = ft_strjoin(av[1], av[2]);
		ft_printf("Result: %s", join);
	}
	ft_printf("\n");
}
 */