/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/02 22:12:57 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_handle_args(int argc, char **argv, t_stack **stack)
{
	int		i;
	t_stack	**stack;

	i = 0;
	while (i < argc)
	{
		if (ft_count_numbers(argv[i]) == 1)
			ft_lstadd_back(stack, &ft_lstnew(ft_atoi(argv[i++])));
		else if (ft_count_numbers(argv[i]) > 1)
			ft_single_arg(argv[i++], stack);
		else
			ft_error();
	}
}

int	ft_single_arg(char *arg, t_stack **stack)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(arg, " \t");
	while (i < ft_count_numbers(arg))
		ft_lstadd_back(stack, &ft_lstnew(ft_atoi(args[i++])));
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc > 1)
		ft_handle_args(argc, argv, stack_a);
	else
		return (-1);
	return (0);
}
