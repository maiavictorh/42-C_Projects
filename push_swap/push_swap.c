/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/14 14:28:24 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function is for test purpose */
void	print_stack(t_stack *stack, char c)
{
	while (stack)
	{
		printf(" %d\n", stack->data);
		stack = stack->next;
	}
	printf("===\n %c\n_________________________________\n\n", c);
}
/* ================================= */

void	single_arg(char *arg, t_stack **stack, int num_count, int value)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(arg, ' ');
	if (!args)
		free_on_error(stack, NULL);
	while (i < num_count)
	{
		if (!ft_atoi(args[i], &value))
			free_on_error(stack, args);
		ft_stackadd_back(stack, ft_new_node(value));
		i++;
	}
	ft_free_split(args);
}

void	args_to_stack(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		value;
	int		num_count;

	i = 1;
	while (i < argc)
	{
		num_count = count_numbers(argv[i]);
		if (num_count == 1)
		{
			if (!ft_atoi(argv[i], &value))
				free_on_error(stack, NULL);
			ft_stackadd_back(stack, ft_new_node(value));
		}
		else if (num_count > 1)
			single_arg(argv[i], stack, num_count, value);
		else
			free_on_error(stack, NULL);
		i++;
	}
	verif_double(*stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		args_to_stack(argc, argv, &stack_a);
		print_stack(stack_a, 'A');
		sort_stack(&stack_a, &stack_b);
		print_stack(stack_a, 'A');
		ft_stackclear(&stack_a);
	}
	else
		return (-1);
	return (0);
}
