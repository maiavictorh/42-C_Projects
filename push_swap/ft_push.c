/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:22:56 by victode-          #+#    #+#             */
/*   Updated: 2026/01/14 14:21:35 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_dst, t_stack **stack_src)
{
	t_stack	*first;

	first = *stack_src;
	*stack_src = (*stack_src)->next;
	first->next = *stack_dst;
	*stack_dst = first;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_b) > 0)
	{
		push(stack_a, stack_b);
		write (1, "pa\n", 3);
	}
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (ft_stacksize(*stack_a) > 0)
	{
		push(stack_b, stack_a);
		write (1, "pb\n", 3);
	}
}
