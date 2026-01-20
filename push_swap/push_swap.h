/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:38:51 by victode-          #+#    #+#             */
/*   Updated: 2026/01/20 15:48:56 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef long long			t_ll;
typedef unsigned long long	t_ull;
typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* ============= Sorting ============= */

int		is_sorted(t_stack *stack);
int		find_smallest(t_stack *stack);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

/* ========== Radix ========== */

int		*stack_to_array(t_stack *stack_a);
void	sort_int_arr(int *arr, int size);
void	init_index(t_stack *stack_a);
int		get_max_bits(t_stack *stack);
void	radix(t_stack **stack_a, t_stack **stack_b);

/* ======== Utils ======== */

int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_atoi(char *nptr, int *result);
int		count_numbers(char *s);
char	**ft_split(char *s, char c);
void	ft_free_split(char **split);
void	free_on_error(t_stack **stack, char **split);

/* ======== Stack operations ======== */

t_stack	*ft_new_node(int data);
t_stack	*ft_last_node(t_stack *node);
int		ft_stacksize(t_stack *stack);
void	ft_stackclear(t_stack **stack);
void	verif_double(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new_node);

/* ======== Push_swap operations ======== */

void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack_dst, t_stack **stack_src);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

#endif