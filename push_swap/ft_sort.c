/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:49:21 by victode-          #+#    #+#             */
/*   Updated: 2026/01/10 20:15:26 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **stack_a, t_stack **stack_b);

void	ft_sort_4(t_stack **stack_a, t_stack **stack_b);

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b);

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		size;

	temp = *stack_a;
	size = ft_stacksize(*stack_a);
	if (size == 2)
	{
		if (temp->data > temp->next->data)
			ft_sa(stack_a);
	}
	(void)stack_b;
	// else if (size == 3)
	// 	ft_sort_3(stack_a, stack_b);
	// else if (size == 4)
	// 	ft_sort_4(stack_a, stack_b);
	// else if (size == 5)
	// 	ft_sort_5(stack_a, stack_b);
}
