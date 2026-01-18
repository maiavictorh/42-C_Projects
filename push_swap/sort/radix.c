/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:05:38 by victode-          #+#    #+#             */
/*   Updated: 2026/01/18 18:29:59 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_index(t_stack *stack_a)
{
	int		i;
	int		*arr;
	int		size;
	t_stack	*temp;

	arr = stack_to_array(stack_a);
	if (!arr)
		free_on_error(&stack_a, NULL);
	size = ft_stacksize(stack_a);
	sort_int_arr(arr, size);
	temp = stack_a;
	while (temp)
	{
		i = -1;
		while (i < size)
		{
			if (temp->data == arr[++i])
			{
				temp->index = i;
				break ;
			}
		}
		temp = temp->next;
	}
	free(arr);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	bit;
	int	size;
	int	max_bits;

	init_index(*stack_a);
	bit = 0;
	size = ft_stacksize(*stack_a);
	max_bits = get_max_bits(*stack_a);
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->index >> bit & 1) == 0)
				pb(stack_b, stack_a);
			else
				ra(stack_a);
			i++;
		}
		bit++;
		while (ft_stacksize(*stack_b))
			pa(stack_a, stack_b);
	}
}
