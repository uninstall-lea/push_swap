/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:25:04 by lbisson           #+#    #+#             */
/*   Updated: 2022/03/04 19:25:53 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	check_duplicate(int size, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (i + j < size)
		{
			if (arr[i] == arr[i + j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	is_int_range(const char *nptr)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = (res * 10) + (*nptr - '0');
		if (res * sign < INT_MIN || res * sign > INT_MAX)
			return (FALSE);
		nptr++;
	}
	if (!ft_isdigit(*nptr) && *nptr)
		return (FALSE);
	return (TRUE);
}

int	check_int_range(char **args)
{
	int				i;

	i = 0;
	while (args[i])
	{
		if (!is_int_range(args[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	check_nargs(int ac)
{
	if (ac == 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	check_error(char **args, t_stack *a, t_stack *b,
		int to_free_or_not_to_free)
{
	if (!check_duplicate(a->size, a->arr)
		|| !check_int_range(args))
	{
		free((free(a->arr), b->arr));
		write(2, "Error\n", 6);
		if (to_free_or_not_to_free)
			free_split(args);
		exit(EXIT_FAILURE);
	}
}
