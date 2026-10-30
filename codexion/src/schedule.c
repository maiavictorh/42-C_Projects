/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedule.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:56:34 by victode-          #+#    #+#             */
/*   Updated: 2026/10/30 03:10:10 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static int	compare_sequence(t_request *request_1, t_request *request_2)
{
	if (request_1->sequence < request_2->sequence)
		return (-1);
	else if (request_1->sequence > request_2->sequence)
		return (1);
	return (0);
}

static int	compare_time(t_request *request_1, t_request *request_2)
{
	if (request_1->request_time < request_2->request_time)
		return (-1);
	else if (request_1->request_time > request_2->request_time)
		return (1);
	else
		return (compare_sequence(request_1, request_2));
}

// Compares two requests: -1 if first has priority, 1 if second has priority
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

void	heap_insert(int scheduler, t_heap *heap, t_request *request)
{
	int			i;
	int			parent;
	t_request	temp;

	if (heap->size < heap->capacity)
	{
		heap->requests[heap->size] = *request;
		heap->size++;
		i = heap->size - 1;
		while (i > 0)
		{
			parent = (i - 1) / 2;
			if (compare_requests(scheduler,\
				&heap->requests[i], &heap->requests[parent]) >= 0)
				break ;
			temp = heap->requests[i];
			heap->requests[i] = heap->requests[parent];
			heap->requests[parent] = temp;
			i = parent;
		}
	}
}

void	schedule(t_manager *manager);
