/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:06:10 by victode-          #+#    #+#             */
/*   Updated: 2025/11/12 14:14:28 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Calculates the length of a word in a string until a given delimiter.
 *
 * @param s The input string to check.
 * @param c The delimiter character that separates words.
 * @return The length of the word before the delimiter or end of string.
 */
static t_ull	ft_word_len(char const *s, char c)
{
	t_ull	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/**
 * @brief Counts the number of words in a string separated by a given delimiter.
 *
 * @param s The input string to analyze.
 * @param c The delimiter character used to split the string.
 * @return The total number of words found in the string.
 */
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

/**
 * @brief Frees a NULL-terminated array of strings.
 *
 * This function iterates through each string in the given array,
 * freeing them one by one, and then frees the array itself.
 *
 * @param split The NULL-terminated array of strings to free.
 */
static void	free_split(char **split)
{
	t_ull	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

/**
 * @brief Splits a string into words separated by a given delimiter.
 *
 * This function fills the provided array of strings ('split') with
 * substrings from the input string 's', using the delimiter 'c' to
 * determine word boundaries. Memory for each substring is dynamically
 * allocated. If allocation fails, all previously allocated memory is
 * freed and the function returns NULL.
 *
 * @param s The input string to be split.
 * @param c The delimiter character used to separate words.
 * @param split The array of strings to be filled with substrings.
 * @return A pointer to the array of split strings, or NULL if allocation fails.
 */
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

/**
 * @brief Splits a string into an array of substrings using
 * 		  a delimiter character.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return A NULL-terminated array of strings (each allocated separately),
 *         or NULL if memory allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split)
		return (NULL);
	return (split_words(s, c, split));
}

/* int main(int ac, char **av)
{
	if (ac == 3 && ft_strlen(av[2]) == 1)
	{
		char **split = ft_split(av[1], av[2][0]);

		ft_printf("Result:\n");
		for (t_ull i = 0; i < ft_word_count(av[1], av[2][0]); i++)
		{
			ft_printf("   \"%s\"\n", split[i]);
			free(split[i]);
		}
		ft_printf("Word count: %u", ft_word_count(av[1], av[2][0]));
	}
	ft_printf("\n");
}
 */