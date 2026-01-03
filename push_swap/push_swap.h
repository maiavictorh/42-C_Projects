/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:38:51 by victode-          #+#    #+#             */
/*   Updated: 2026/01/03 17:22:03 by victode-         ###   ########.fr       */
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
int		ft_atoi(const char *nptr);
int		ft_count_numbers(const char *s);
void	free_split(char **split);
char	**ft_split(char *s, char c);

/* ======== list functions ======== */

t_stack	*ft_new_node(int data);
t_stack	*ft_last_node(t_stack *node);
void	ft_lstadd_back(t_stack **stack, t_stack *new_node);
void	ft_lstadd_front(t_stack **stack, t_stack *new_node);

#endif