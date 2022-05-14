/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:23:38 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/02 05:14:26 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static int	get_nb_moves(int i, int range)
{
	if (i < range / 2)
		return (i);
	return (range - i);
}

int	calcul_moves(int range, t_stack *b)
{
	int	i_min;
	int	i_max;

	i_min = get_min(b);
	i_max = get_max(b);
	if (get_nb_moves(i_min, range) < get_nb_moves(i_max, range))
		return (i_min);
	return (i_max);
}

/* move_up considering if we use ra or rra
before the middle -> ra
after -> rra */
void	move_up(int index, t_stack *stack)
{
	if (index < stack->size / 2)
	{	
		while (index)
		{
			rotate(stack);
			index--;
		}
	}
	else
	{	
		while (index < stack->size)
		{
			rrotate(stack);
			index++;
		}
	}
}
