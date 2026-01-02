/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:38:51 by victode-          #+#    #+#             */
/*   Updated: 2026/01/02 16:58:27 by victode-         ###   ########.fr       */
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
	int				value;
	struct s_stack	*next;
}	t_stack;

/* ======== Utils ======== */

void	ft_error(void);
int		ft_atoi_custom(const char *nptr);

#endif