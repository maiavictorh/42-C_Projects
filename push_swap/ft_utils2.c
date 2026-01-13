/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:37:04 by victode-          #+#    #+#             */
/*   Updated: 2026/01/13 16:07:27 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_smallest(t_stack *stack)
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
