/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:46:46 by victode-          #+#    #+#             */
/*   Updated: 2026/11/09 23:20:24 by victode-         ###   ########.fr       */
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
