/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/03 17:47:41 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_single_arg(char *arg, t_stack **stack)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(arg, ' ');
	while (i < ft_count_numbers(arg))
		ft_lstadd_back(stack, ft_new_node(ft_atoi(args[i++])));
}

void	ft_handle_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		printf("%d\n", ft_count_numbers(argv[i]));
		if (ft_count_numbers(argv[i]) == 1)
			ft_lstadd_back(stack_a, ft_new_node(ft_atoi(argv[i++])));
		else if (ft_count_numbers(argv[i]) > 1)
			ft_single_arg(argv[i++], stack_a);
		else
			ft_error();
	}
	for (int i = 0; stack_a[i]; i++)
		printf("%d", stack_a[i]->data);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		printf("\n");
		for (int i = 0; i < argc; i++)
			printf("%s\n", argv[i]);
		printf("\n");
		ft_handle_args(argc, argv, &stack_a);
	}
	else
		return (-1);
	return (0);
}
