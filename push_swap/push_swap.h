/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:38:51 by victode-          #+#    #+#             */
/*   Updated: 2026/01/03 22:43:31 by victode-         ###   ########.fr       */
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

void	ft_error(void);
int		ft_isdigit(int c);
int		ft_atoi(char *nptr);
int		ft_count_numbers(char *s);
void	ft_free_split(char **split);
void	ft_free_stack(char **stack);
char	**ft_split(char *s, char c);

/* ======== Stack operations ======== */

t_stack	*ft_new_node(int data);
t_stack	*ft_last_node(t_stack *node);
void	ft_verif_double(t_stack *stack);
void	ft_lstadd_back(t_stack **stack, t_stack *new_node);
void	ft_lstadd_front(t_stack **stack, t_stack *new_node);

#endif