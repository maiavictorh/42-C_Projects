/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:27:40 by victode-          #+#    #+#             */
/*   Updated: 2026/01/14 18:08:04 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	*stack = first->next;
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **stack_a)
{
	if (ft_stacksize(*stack_a) > 1)
	{
		rotate(stack_a);
		write (1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b)
{
	if (ft_stacksize(*stack_b) > 1)
	{
		rotate(stack_b);
		write (1, "rb\n", 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) > 1 && ft_stacksize(*stack_b) > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		write (1, "rr\n", 3);
	}
}
