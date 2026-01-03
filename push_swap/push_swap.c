/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/03 22:34:56 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	printf("Init A:\n");
	while (stack)
	{
		printf(" %d\n", stack->data);
		stack = stack->next;
	}
	printf("===\n A\n");
}

void	ft_single_arg(char *arg, t_stack **stack)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(arg, ' ');
	while (i < ft_count_numbers(arg))
		ft_lstadd_back(stack, ft_new_node(ft_atoi(args[i++])));
	ft_free_split(args);
}

void	ft_handle_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		num_count;

	i = 1;
	while (i < argc)
	{
		num_count = ft_count_numbers(argv[i]);
		// printf("Num count: %d\n", num_count);
		if (num_count == 1)
			ft_lstadd_back(stack_a, ft_new_node(ft_atoi(argv[i++])));
		else if (num_count > 1)
			ft_single_arg(argv[i++], stack_a);
		else
			ft_error();
	}
	ft_verif_double(*stack_a);
	print_stack(*stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	(void)stack_b;
	if (argc > 1)
	{
		printf("\n");
		for (int i = 0; i < argc; i++)
			printf("%s ", argv[i]);
		printf("\n\n");
		ft_handle_args(argc, argv, &stack_a);
	}
	else
		return (-1);
	return (0);
}
