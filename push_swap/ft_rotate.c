/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:27:40 by victode-          #+#    #+#             */
/*   Updated: 2026/01/08 16:57:25 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack && *stack && (*stack)->next)
	{
		first = *stack;
		*stack = first->next;
		last = first;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

void	ft_ra(t_stack **stack_a)
{
	if (ft_stacksize(*stack_a) > 1)
	{
		ft_rotate(stack_a);
		write (1, "ra\n", 3);
	}
}

void	ft_rb(t_stack **stack_b)
{
	if (ft_stacksize(*stack_b) > 1)
	{
		ft_rotate(stack_b);
		write (1, "rb\n", 3);
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) > 1 && ft_stacksize(*stack_b) > 1)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		write (1, "rr\n", 3);
	}
}
