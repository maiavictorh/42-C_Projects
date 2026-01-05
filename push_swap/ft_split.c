/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:18:13 by victode-          #+#    #+#             */
/*   Updated: 2026/01/05 18:54:12 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_word_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static t_ull	ft_word_count(char *s, char c)
{
	t_ull	i;
	t_ull	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_strndup(char *s, int n)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

static char	**split_words(char *s, char c, char **split)
{
	t_ull	i;
	t_ull	j;
	t_ull	wd_len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			wd_len = ft_word_len(s + i, c);
			split[j] = ft_strndup(s + i, wd_len);
			if (!split[j])
				return (ft_free_split(split), ft_error(), NULL);
			j++;
			i += wd_len;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char *s, char c)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split)
		return (NULL);
	return (split_words(s, c, split));
}
