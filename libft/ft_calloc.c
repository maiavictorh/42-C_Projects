/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:47:14 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 13:59:07 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocates and clears a block of memory.
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/* 
int main(void)
{
	int *tab = (int *)ft_calloc(5, sizeof(int));

	ft_printf("\n1. Integer tab test:\n");
	if (!tab)
		return 1;
	for (int i = 0; i < 5; i++)
		ft_printf("tab[%d] = %d\n", i, tab[i]);
	free(tab);

	char *s = (char *)ft_calloc(20, sizeof(char));

	ft_printf("\n2. String test:\n");
	if (!s)
		return 1;
	ft_printf("Empty String: \"");
	for (int i = 0; i < 12; i++)
		ft_printf("%d", s[i]);
	ft_strlcpy(s, "Hello World", 12);
	ft_printf("\"\nAfter copy: \"%s\"\n", s);
	free(s);
}
 */