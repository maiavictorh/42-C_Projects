/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:31:50 by victode-          #+#    #+#             */
/*   Updated: 2026/01/14 18:07:16 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_split(char **split)
{
	t_ull	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_on_error(t_stack **stack, char **split)
{
	if (stack)
		ft_stackclear(stack);
	if (split)
		ft_free_split(split);
	ft_error();
}
