/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:58:45 by victode-          #+#    #+#             */
/*   Updated: 2026/01/06 15:48:02 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*save;

	if (*stack && (*stack)->next)
	{
		save = (*stack)->next;
		save = save->next;
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = save;
		(*stack)->next = temp;
	}
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	write (1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	write (1, "sb\n", 3);	
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	write (1, "ss\n", 3);
}
