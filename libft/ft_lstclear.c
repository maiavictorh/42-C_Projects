/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:04:25 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 13:51:10 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function 'del' and free. Finally, the pointer to the list must
 * be set to NULL.
 *
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content
 * of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (*lst && del)
	{
		while (*lst)
		{
			next = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next;
		}
	}
	*lst = NULL;
}
