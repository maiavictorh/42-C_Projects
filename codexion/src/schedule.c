/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedule.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:56:34 by victode-          #+#    #+#             */
/*   Updated: 2026/10/29 03:16:40 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static int	fifo_request(t_request *request_1, t_request *request_2)
{
	if (request_1->request_time < request_2->request_time)
		return (-1);
	else if (request_1->request_time > request_2->request_time)
		return (1);
	return (0);
}

int	compare_requests(int scheduler, t_request *request_1, t_request *request_2)
{
	if (scheduler == FIFO)
		return (fifo_request(request_1, request_2));
	else if (scheduler == EDF)
	{
		if (request_1->deadline < request_2->deadline)
			return (-1);
		else if (request_1->deadline > request_2->deadline)
			return (1);
		else
			return (fifo_request(request_1, request_2));
	}
	return (0);
}

void	schedule(t_manager *manager);
