/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/01 18:18:20 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_single_arg(char **args);

void	ft_multi_args();

int	main(int argc, char **argv)
{
	t_list	**stack;
	char	**args;

	if (argc == 2)
		ft_single_arg(ft_split(argv[1], ' '));
	else if (argc > 2)
		ft_multi_args();
	else
		return (-1);
	return (0);
}
