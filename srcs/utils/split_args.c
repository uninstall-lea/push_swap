/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:23:38 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/02 05:14:26 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static size_t	nb_args(const char *str)
{
	size_t	nb_args;

	nb_args = 0;
	while (*str)
	{
		printf("the arg: %d\n", *str);
		while (*str && ft_strchr(WHITESPACES, *str))
			str++;
		if (*str && !ft_strchr(WHITESPACES, *str))
			nb_args++;
		while (*str && !ft_strchr(WHITESPACES, *str))
			str++;
	}
	return (nb_args);
}

static size_t	arg_len(const char *str)
{
	size_t	arg_len;

	arg_len = 0;
	while (*str && !ft_strchr(WHITESPACES, *str))
	{
		arg_len++;
		str++;
	}
	return (arg_len);
}

static void	create_and_fill(size_t nb_args, const char *s, char **str)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (i < nb_args)
	{
		while (s[j] && ft_strchr(WHITESPACES, s[j]))
			j++;
		len = arg_len(s + j);
		str[i] = ft_substr(s, j, len);
		if (!str[i])
		{
			free_split(str);
			return ;
		}
		while (s[j] && !ft_strchr(WHITESPACES, s[j]))
			j++;
		i++;
	}
}

char	**split_args(char const *s)
{
	size_t	nargs;
	char	**split_str;

	if (!s)
		return (NULL);
	nargs = nb_args(s);
	printf("nargs: %lu\n", nargs);
	split_str = malloc(sizeof(char *) * (nargs + 1));
	if (!split_str)
		return (NULL);
	split_str[nargs] = NULL;
	create_and_fill(nargs, s, split_str);
	return (split_str);
}
