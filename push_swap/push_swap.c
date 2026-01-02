/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/02 16:47:29 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_handle_args(char **argv);

t_stack	**ft_single_arg(char *arg, t_stack **stack)
{
	if (!*arg)
		ft_error();
	while (*arg)
	{
		while (ft_isspace(*arg))
			arg++;
	}
	return (stack);
}

t_stack	**ft_multi_args(int argc, char **argv, t_stack **stack)
{
	t_ull	i;

	i = 0;
	stack = ft_lstnew(ft_atoi_custom(argv[i++]));
	while (i < argc)
		ft_lstadd_back(stack, ft_atoi_custom(argv[i++]));
}

int	main(int argc, char **argv)
{
	t_stack	**stack;
	char	**args;

	if (argc > 1)
		ft_handle_args(argc, argv);
	else
		return (-1);
	return (0);
}
