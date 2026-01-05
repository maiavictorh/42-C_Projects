/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:39:19 by victode-          #+#    #+#             */
/*   Updated: 2026/01/05 19:14:06 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function is just for test purpose */
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

void	ft_handle_args(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		j;
	int		num_count;
	char	**args;

	i = 1;
	while (i < argc)
	{
		num_count = ft_count_numbers(argv[i]);
		// printf("Num count: %d\n", num_count);
		if (num_count == 1)
			ft_lstadd_back(stack, ft_new_node(ft_atoi(argv[i++], stack)));
		else if (num_count > 1)
		{
			j = 0;
			args = ft_split(argv[i], ' ');
			while (j < num_count)
				ft_lstadd_back(stack, ft_new_node(ft_atoi(args[j++], stack)));
			ft_free_split(args);
			i++;
		}
		else
			ft_free_on_error(stack);
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

		printf("\n");
		for (int i = 0; i < argc; i++)
			printf("%s ", argv[i]);
		printf("\n\n");

		ft_handle_args(argc, argv, &stack_a);
		print_stack(stack_a);
		ft_lstclear(&stack_a);
	}
	else
		return (-1);
	return (0);
}
