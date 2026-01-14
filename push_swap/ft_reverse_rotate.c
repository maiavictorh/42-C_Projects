/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:39:10 by victode-          #+#    #+#             */
/*   Updated: 2026/01/14 14:22:10 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	while (last->next->next)
		last = last->next;
	(*stack)->next = first;
	last->next = NULL;
}

void	rra(t_stack **stack_a)
{
	if (ft_stacksize(*stack_a) > 1)
	{
		reverse_rotate(stack_a);
		write (1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b)
{
	if (ft_stacksize(*stack_b) > 1)
	{
		reverse_rotate(stack_b);
		write (1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) > 1)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write (1, "rrr\n", 4);
	}
}
