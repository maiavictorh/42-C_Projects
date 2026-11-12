/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:23:06 by victode-          #+#    #+#             */
/*   Updated: 2026/11/12 17:31:45 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

int	compile(t_coder *coder);

int	debug(t_coder *coder);

int	refactor(t_coder *coder);

void	*coder_routine(void *arg)
{
	int			comp;
	t_coder		*coder;

	comp = 0;
	coder = (t_coder *)arg;
	while (comp < coder->compiles_done)
	{
		comp++;
	}
}
