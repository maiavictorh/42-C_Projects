/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:56:34 by victode-          #+#    #+#             */
/*   Updated: 2026/10/31 01:08:51 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static int	compare_time(t_request *request_1, t_request *request_2)
{
	if (request_1->request_time < request_2->request_time)
		return (-1);
	else if (request_1->request_time > request_2->request_time)
		return (1);
	else
	{
		if (request_1->sequence < request_2->sequence)
			return (-1);
		else if (request_1->sequence > request_2->sequence)
			return (1);
	}
	return (0);
}

// Compares two requests: -1 if first has priority, 1 if second has priority.
int	compare_requests(int scheduler, t_request *request_1, t_request *request_2)
{
	if (scheduler == FIFO)
		return (compare_time(request_1, request_2));
	else if (scheduler == EDF)
	{
		if (request_1->deadline < request_2->deadline)
			return (-1);
		else if (request_1->deadline > request_2->deadline)
			return (1);
		else
			return (compare_time(request_1, request_2));
	}
	return (0);
}

void	swap_requests(t_request *request_1, t_request *request_2)
{
	t_request	temp;

	temp = *request_1;
	*request_1 = *request_2;
	*request_2 = temp;
}

void	heap_insert(int scheduler, t_heap *heap, t_request *request)
{
	int			i;
	int			parent;

	if (heap->size < heap->capacity)
	{
		heap->requests[heap->size] = *request;
		heap->size++;
		i = heap->size - 1;
		while (i > 0)
		{
			parent = (i - 1) / 2;
			if (compare_requests(scheduler,
					&heap->requests[i], &heap->requests[parent]) >= 0)
				break ;
			swap_requests(&heap->requests[i], &heap->requests[parent]);
			i = parent;
		}
	}
}

// (2 * i + 1) is used to represent the current item's left son.
int	heap_pop(int scheduler, t_heap *heap, t_request *request)
{
	int			i;
	int			right;
	int			best;

	if (!heap || !heap->size || !request)
		return (0);
	*request = heap->requests[0];
	heap->requests[0] = heap->requests[heap->size - 1];
	heap->size--;
	i = 0;
	while ((2 * i + 1) < heap->size)
	{
		best = 2 * i + 1;
		right = 2 * i + 1 + 1;
		if (right < heap->size && compare_requests(scheduler,
				&heap->requests[2 * i + 1], &heap->requests[right]) > 0)
			best = right;
		if (compare_requests(scheduler,
				&heap->requests[i], &heap->requests[best]) <= 0)
			break ;
		swap_requests(&heap->requests[i], &heap->requests[best]);
		i = best;
	}
	return (1);
}
