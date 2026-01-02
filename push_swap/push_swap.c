/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/02 02:38:50 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_single_arg(char *arg)
{
	if (!*arg)
		ft_error();
}

t_stack	ft_multi_args(char **args);

int	main(int argc, char **argv)
{
	t_stack	**stack;
	char	**args;

	if (argc == 2)
		ft_single_arg();
	else if (argc > 2)
		ft_multi_args();
	else
		return (-1);
	return (0);
}
