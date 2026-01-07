/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:22:56 by victode-          #+#    #+#             */
/*   Updated: 2026/01/07 14:53:52 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_dst, t_stack **stack_src)
{
	t_stack	*first;

	if (stack_src && *stack_src)
	{
		first = *stack_src;
		*stack_src = (*stack_src)->next;
		first->next = *stack_dst;
		*stack_dst = first;
	}
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write (1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write (1, "pb\n", 3);
}
