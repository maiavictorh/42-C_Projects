/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:22:05 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 13:51:01 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocates memory and returns a new node.
 *        The member variable 'content' is initialized with the value of the
 *        parameter 'content'.
 *        The variable 'next' is initialized to NULL.
 *
 * @param content The content to create the node with.
 * @return The new node, or NULL if the allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
