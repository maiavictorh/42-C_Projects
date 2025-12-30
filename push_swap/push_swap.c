/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2025/12/30 16:55:39 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_numbers(char **args);

void	ft_single_arg(char **args);

void	ft_multi_args();

int	main(int argc, char **argv)
{
	t_list	**stack;

	if (argc == 2)
	{
		char	**args;
		args = ft_split(argv[1], ' ');
		ft_single_arg(args);
	}
	else if (argc > 2)
	{
		ft_multi_args();
	}
	else
		return (ERROR);
	return (0);
}
