/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:37:04 by victode-          #+#    #+#             */
/*   Updated: 2026/01/18 16:27:21 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_smallest(t_stack *stack)
{
	t_stack	*temp;
	int		i;
	int		index;
	int		smallest;

	temp = stack;
	i = 0;
	index = 0;
	smallest = temp->data;
	while (temp)
	{
		if (temp->data < smallest)
		{
			smallest = temp->data;
			index = i;
		}
		i++;
		temp = temp->next;
	}
	return (index);
}

int	*stack_to_array(t_stack *stack_a)
{
	int		i;
	int		*arr;
	t_stack	*cursor;

	i = 0;
	arr = malloc(ft_stacksize(stack_a) * sizeof(int));
	if (!arr)
		return (NULL);
	cursor = stack_a;
	while (cursor)
	{
		arr[i++] = cursor->data;
		cursor = cursor->next;
	}
	return (arr);
}

void	sort_int_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	get_max_bits(t_stack *stack)
{
	t_stack	*temp;
	int		bit;
	int		max;

	temp = stack;
	bit = 0;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while (max > 0)
	{
		bit++;
		max /= 2;
	}
	return (bit);
}
