/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:31:50 by victode-          #+#    #+#             */
/*   Updated: 2026/01/15 17:58:26 by victode-         ###   ########.fr       */
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
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	count_numbers(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] == '+' || s[i] == '-')
		{
			if (!ft_isdigit(s[++i]))
				return (0);
		}
		if (s[i] && ft_isdigit(s[i]))
			count++;
		while (s[i] && ft_isdigit(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
			return (0);
	}
	return (count);
}
