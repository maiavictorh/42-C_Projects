/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:06:13 by victode-          #+#    #+#             */
/*   Updated: 2026/01/14 18:07:09 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_stackadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

int	ft_stacksize(t_stack *stack)
{
	size_t	count;

	count = 0;
	if (!stack)
		return (count);
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*next;

	if (!stack)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

void	verif_double(t_stack *stack)
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
				free_on_error(&stack, NULL);
			temp = temp->next;
		}
		cursor = cursor->next;
	}
}
