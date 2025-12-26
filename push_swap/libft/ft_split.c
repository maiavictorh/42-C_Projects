/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:06:10 by victode-          #+#    #+#             */
/*   Updated: 2025/12/26 16:16:45 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ull	ft_word_len(char const *s, char c)
{
	t_ull	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static t_ull	ft_word_count(char const *s, char c)
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

static void	free_split(char **split)
{
	t_ull	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**split_words(char const *s, char c, char **split)
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
			split[j] = ft_substr(s, i, wd_len);
			if (!split[j])
				return (free_split(split), NULL);
			j++;
			i += wd_len;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split)
		return (NULL);
	return (split_words(s, c, split));
}
