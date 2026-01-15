/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:49:21 by victode-          #+#    #+#             */
/*   Updated: 2026/01/15 14:50:22 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
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

void	sort_3(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack_a;
	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	if (first->data > second->data && first->data < third->data)
		sa(stack_a);
	else if (first->data > third->data && third->data > second->data)
		ra(stack_a);
	else if (first->data > third->data && first->data < second->data)
		rra(stack_a);
	else if (first->data < third->data && third->data < second->data)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (third->data < second->data && second->data < first->data)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	index_smallest;

	index_smallest = find_smallest(*stack_a);
	if (index_smallest == 1)
		sa(stack_a);
	else if (index_smallest == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (index_smallest == 3)
		rra(stack_a);
	pb(stack_b, stack_a);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	index_smallest;

	index_smallest = find_smallest(*stack_a);
	if (index_smallest == 1)
		sa(stack_a);
	else if (index_smallest == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (index_smallest == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (index_smallest == 4)
		rra(stack_a);
	pb(stack_b, stack_a);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		size;

	if (is_sorted(*stack_a))
		return ;
	temp = *stack_a;
	size = ft_stacksize(*stack_a);
	if (size == 2)
	{
		if (temp->data > temp->next->data)
			sa(stack_a);
	}
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else if (size > 5)
		radix(stack_a, stack_b);
}
