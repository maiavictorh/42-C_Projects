/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/06 15:45:43 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function is for test purpose */
void	print_stack(t_stack *stack)
{
	printf("\nInit A:\n");
	while (stack)
	{
		printf(" %d\n", stack->data);
		stack = stack->next;
	}
	printf("===\n A\n\n");
}

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
		// printf("Num count: %d\n", num_count);
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
	(void)stack_b;
	if (argc > 1)
	{
		// printf("\n");
		// for (int i = 0; i < argc; i++)
		// 	printf("%s ", argv[i]);
		// printf("\n\n");
		ft_handle_args(argc, argv, &stack_a);
		print_stack(stack_a);
		ft_sa(&stack_a);
		print_stack(stack_a);
		ft_lstclear(&stack_a);
	}
	else
		return (-1);
	return (0);
}
