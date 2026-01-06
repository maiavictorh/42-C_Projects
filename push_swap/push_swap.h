/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:38:51 by victode-          #+#    #+#             */
/*   Updated: 2026/01/06 18:16:54 by victode-         ###   ########.fr       */
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
	struct s_stack	*next;
}	t_stack;

/* ======== Utils ======== */

int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_atoi(char *nptr, int *result);
int		ft_count_numbers(char *s);
char	**ft_split(char *s, char c);

/* ======== Error handling ======== */

void	ft_error(void);
void	ft_free_split(char **split);
void	ft_free_on_error(t_stack **stack, char **split);

/* ======== Stack operations ======== */

t_stack	*ft_new_node(int data);
int		ft_lstsize(t_stack *stack);
void	ft_lstclear(t_stack **stack);
void	ft_verif_double(t_stack *stack);
void	ft_lstadd_back(t_stack **stack, t_stack *new_node);
void	ft_lstadd_front(t_stack **stack, t_stack *new_node);

/* ======== Push_swap operations ======== */

void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

/* ======== Extra ======== */
void	print_stack(t_stack *stack);

#endif