/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:23:38 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/02 05:14:26 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_words(char const *str, char c)
{
	size_t	nb_words;

	nb_words = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			nb_words++;
		while (*str && *str != c)
			str++;
	}
	return (nb_words);
}

static size_t	ft_word_len(const char *str, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*str && *str != c)
	{
		word_len++;
		str++;
	}
	return (word_len);
}

static void	ft_free(char **str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	create_and_fill(char **str, char const *s, char c, size_t nb_words)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	while (i < nb_words)
	{
		while (s[j] && s[j] == c)
			j++;
		word_len = ft_word_len(s + j, c);
		str[i] = ft_substr(s, j, word_len);
		if (!str[i])
		{
			ft_free(str, i);
			return ;
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	**split_str;

	if (!s)
		return (NULL);
	nb_words = ft_nb_words(s, c);
	split_str = malloc(sizeof(char *) * (nb_words + 1));
	if (!split_str)
		return (NULL);
	split_str[nb_words] = NULL;
	create_and_fill(split_str, s, c, nb_words);
	return (split_str);
}
