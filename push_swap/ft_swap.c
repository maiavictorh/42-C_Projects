/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:58:45 by victode-          #+#    #+#             */
/*   Updated: 2026/01/08 16:39:00 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*third;

	if (stack && *stack && (*stack)->next)
	{
		third = (*stack)->next;
		third = third->next;
		first = *stack;
		*stack = (*stack)->next;
		first->next = third;
		(*stack)->next = first;
	}
}

void	ft_sa(t_stack **stack_a)
{
	if (ft_stacksize(*stack_a) > 1)
	{
		ft_swap(stack_a);
		write (1, "sa\n", 3);
	}
}

void	ft_sb(t_stack **stack_b)
{
	if (ft_stacksize(*stack_b) > 1)
	{
		ft_swap(stack_b);
		write (1, "sb\n", 3);
	}
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) > 1 && ft_stacksize(*stack_b) > 1)
	{
		ft_sa(stack_a);
		ft_sb(stack_b);
		write (1, "ss\n", 3);
	}
}
