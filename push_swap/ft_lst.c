/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:06:13 by victode-          #+#    #+#             */
/*   Updated: 2026/01/05 19:13:45 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	printf("adding %d\n", new_node->data);
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
	// printf("last added\n");
}

void	ft_verif_double(t_stack *stack)
{
	t_stack	*cursor;
	t_stack	*temp;

	cursor = stack;
	while (cursor)
	{
		temp = cursor->next;
		while (temp)
		{
			if (cursor->data == temp->data)
			{
				ft_lstclear(&stack);
				ft_error();
			}
			temp = temp->next;
		}
		cursor = cursor->next;
	}
}

void	ft_lstclear(t_stack **stack)
{
	t_stack	*next;

	// printf("starting remove proceadure\n");
	if (!stack)
		return ;
	while (*stack)
	{
		// printf("freeing %d\n", (*stack)->data);
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}
