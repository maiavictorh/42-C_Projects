/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:17:25 by victode-          #+#    #+#             */
/*   Updated: 2026/01/14 20:13:05 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	init_index(t_stack *stack_a)
{
	int		i;
	int		*arr;
	t_stack	*temp;

	arr = stack_to_array(stack_a);
	if (!arr)
		free_on_error(&stack_a, NULL);
	sort_int_arr(arr, ft_stacksize(stack_a));
	temp = stack_a;
	while (temp)
	{
		i = 0;
		while (i < ft_stacksize(stack_a))
		{
			if (temp->data == arr[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}	
	free(arr);
}
