/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:23:38 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/02 05:14:26 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	get_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 1;
	min = 0;
	while (i < stack->size)
	{
		if (stack->arr[min] > stack->arr[i])
			min = i;
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > stack->arr[max])
			max = i;
		i++;
	}
	return (max);
}

/* Find the first number bigger than to_place to put to_place right before */
int	get_next_min(int to_place, t_stack *stack)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	while (i < stack->size)
	{
		if (stack->arr[i] > to_place)
			if (index == -1 || stack->arr[i] < stack->arr[index])
				index = i;
		i++;
	}
	return (index);
}
