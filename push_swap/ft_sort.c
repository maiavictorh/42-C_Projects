/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:49:21 by victode-          #+#    #+#             */
/*   Updated: 2026/01/13 17:31:39 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*cursor;
	t_stack	*next;

	if (ft_stacksize(stack) == 1)
		return (1);
	cursor = stack;
	while (cursor->next)
	{
		next = cursor->next;
		if (cursor->data > next->data)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

void	ft_sort_3(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	if (temp->data > temp->next->data)
		ft_sa(stack_a);
	temp = (*stack_a)->next;
	if (temp->data > temp->next->data)
		ft_rra(stack_a);
	temp = *stack_a;
	if (temp->data > temp->next->data)
		ft_sa(stack_a);
}

void	ft_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	index_smallest;

	index_smallest = ft_find_smallest(*stack_a);
	if (index_smallest == 1)
		ft_sa(stack_a);
	else if (index_smallest == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (index_smallest == 3)
		ft_rra(stack_a);
	ft_pb(stack_b, stack_a);
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	index_smallest;

	index_smallest = ft_find_smallest(*stack_a);
	if (index_smallest == 1)
		ft_sa(stack_a);
	else if (index_smallest == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (index_smallest == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (index_smallest == 4)
		ft_rra(stack_a);
	ft_pb(stack_b, stack_a);
	ft_sort_4(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		size;

	(void)stack_b;
	if (ft_is_sorted(*stack_a))
		return ;
	temp = *stack_a;
	size = ft_stacksize(*stack_a);
	if (size == 2)
	{
		if (temp->data > temp->next->data)
			ft_sa(stack_a);
	}
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (size == 5)
		ft_sort_5(stack_a, stack_b);
}
