/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:37:27 by victode-          #+#    #+#             */
/*   Updated: 2026/11/13 18:56:22 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

void	swap_requests(t_request *request_1, t_request *request_2)
{
	t_request	temp;

	temp = *request_1;
	*request_1 = *request_2;
	*request_2 = temp;
}

int	is_dongle_available(t_request *request, long current_time)
{
	t_dongle	*left;
	t_dongle	*right;

	left = request->coder->left_dongle;
	right = request->coder->right_dongle;
	return (!left->in_use && !right->in_use
		&& left->available_at <= current_time
		&& right->available_at <= current_time);
}

int	create_request(t_coder *coder)
{
	long		current_time;
	t_request	request;
	t_manager	*manager;
	
	manager = coder->data;
	current_time = get_elapsed_time(manager);
	request.coder = coder;
	request.request_time = current_time;
	request.deadline = coder->last_compile_start + manager->time_to_burnout;
	request.sequence = manager->sequence++;
	if (!heap_insert(manager->scheduler, &manager->heap, &request))
	return (0);
	coder->request_status = RS_WAITING;
	return (1);
}

int	get_best_request(t_manager *manager)
{
	int		i;
	int		best;
	long	current_time;

	i = 0;
	best = -1;
	current_time = get_elapsed_time(manager);
	if (current_time < 0)
		return (-1);
	while (i < manager->heap.size)
	{
		if (is_dongle_available(&manager->heap.requests[i], current_time))
		{
			if (best == -1)
				best = i;
			else if (compare_requests(manager->scheduler,
					&manager->heap.requests[i],
					&manager->heap.requests[best]) < 0)
				best = i;
		}
		i++;
	}
	return (best);
}

void	restore_priority(int scheduler, int index, t_heap *heap)
{
	int	left;
	int	right;
	int	best;

	left = 2 * index + 1;
	while (left < heap->size)
	{
		best = left;
		right = left + 1;
		if (right < heap->size && compare_requests(scheduler,
				&heap->requests[left], &heap->requests[right]) > 0)
			best = right;
		if (compare_requests(scheduler,
				&heap->requests[index], &heap->requests[best]) <= 0)
			break ;
		swap_requests(&heap->requests[index], &heap->requests[best]);
		index = best;
		left = 2 * index + 1;
	}
}
