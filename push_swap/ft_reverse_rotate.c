/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:39:10 by victode-          #+#    #+#             */
/*   Updated: 2026/01/06 23:20:33 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack && *stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while ((*stack)->next)
			*stack = (*stack)->next;
		while (last->next->next)
			last = last->next;
		(*stack)->next = first;
		last->next = NULL;
	}
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	write (1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write (1, "rrr\n", 4);
}
