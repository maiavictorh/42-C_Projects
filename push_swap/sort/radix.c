/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:05:38 by victode-          #+#    #+#             */
/*   Updated: 2026/01/15 18:33:32 by victode-         ###   ########.fr       */
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
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	init_index(*stack_a);
}
