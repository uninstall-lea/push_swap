/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:25:04 by lbisson           #+#    #+#             */
/*   Updated: 2022/05/16 18:45:16 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void	push_chunk(t_chunk chunk, t_stack *src, t_stack *dest)
{
	int	i;
	int	size;

	i = 0;
	size = src->size;
	while (i < size && src->arr[0] <= chunk.max)
	{
		if (src->arr[0] >= chunk.min && src->arr[0] <= chunk.max)
			push(src, dest);
		else
			rotate(src);
		i++;
	}
}

static void	fuck_la_norme(int *rr, t_stack *dest)
{
	rotate(dest);
	*rr = 0;
}

static void	push_back(int range, t_stack *src, t_stack *dest)
{
	int	min;
	int	closest;
	int	rr;

	rr = 0;
	while (src->size)
	{
		min = get_min(src);
		closest = calcul_moves(range, src);
		if (closest > 0 && closest < src->size / 2 && rr)
		{
			rotate_both(src, dest);
			closest = ((min = min- 1), closest - 1);
			rr = 0;
		}
		if (rr)
			fuck_la_norme(&rr, dest);
		move_up(closest, src);
		push(src, dest);
		if (min == closest)
			rr = 1;
	}
	if (rr)
		fuck_la_norme(&rr, dest);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
	int		*a_arr_sort;
	t_chunk	chunk;

	a_arr_sort = init_arr(a);
	if (!a_arr_sort)
		free_stacks(a, b);
	nb_chunks(a->size, &chunk);
	i = chunk.n_chunks;
	while (--i >= 0)
	{
		init_chunk(i, a->size, a_arr_sort, &chunk);
		push_chunk(chunk, a, b);
		push_back(chunk.range, b, a);
		move_up(get_max(a) + 1, a);
	}
	free(a_arr_sort);
}
