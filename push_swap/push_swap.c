/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/07 17:19:38 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* These functions are for test purpose */
void	print_stack(t_stack *stack, char c)
{
	while (stack)
	{
		printf(" %d\n", stack->data);
		stack = stack->next;
	}
	printf("===\n %c\n_________________________________\n\n", c);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("\nInit A:\n");
	print_stack(stack_a, 'A');
	ft_sa(&stack_a);
	printf("\n");
	print_stack(stack_a, 'A');
	ft_ra(&stack_a);
	printf("\n");
	print_stack(stack_a, 'A');
	ft_rra(&stack_a);
	printf("\n");
	print_stack(stack_a, 'A');
	ft_pb(&stack_a, &stack_b);
	printf("\n");
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	ft_pb(&stack_a, &stack_b);
	printf("\n");
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	ft_pa(&stack_a, &stack_b);
	printf("\n");
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
}
/* ==================================== */

void	ft_single_arg(char *arg, t_stack **stack, int num_count, int value)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(arg, ' ');
	if (!args)
		ft_free_on_error(stack, NULL);
	while (i < num_count)
	{
		if (!ft_atoi(args[i], &value))
			ft_free_on_error(stack, args);
		ft_lstadd_back(stack, ft_new_node(value));
		i++;
	}
	ft_free_split(args);
}

void	ft_handle_args(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		value;
	int		num_count;

	i = 1;
	while (i < argc)
	{
		num_count = ft_count_numbers(argv[i]);
		if (num_count == 1)
		{
			if (!ft_atoi(argv[i], &value))
				ft_free_on_error(stack, NULL);
			ft_lstadd_back(stack, ft_new_node(value));
		}
		else if (num_count > 1)
			ft_single_arg(argv[i], stack, num_count, value);
		else
			ft_free_on_error(stack, NULL);
		i++;
	}
	ft_verif_double(*stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		ft_handle_args(argc, argv, &stack_a);
		// print_stacks(stack_a, stack_b);
		ft_lstclear(&stack_a);
	}
	else
		return (-1);
	return (0);
}
