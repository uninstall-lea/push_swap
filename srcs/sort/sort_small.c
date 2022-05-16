/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:23:38 by lbisson           #+#    #+#             */
/*   Updated: 2022/05/16 18:45:35 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void	sort_2(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1])
		swap(stack);
}

static void	sort_3(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2]
		&& stack->arr[2] > stack->arr[0])
		swap(stack);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2])
		rotate(stack);
	else if (stack->arr[0] > stack->arr[1])
	{
		swap(stack);
		rrotate(stack);
	}
	else if (stack->arr[1] > stack->arr[2] && stack->arr[2] > stack->arr[0])
	{
		swap(stack);
		rotate(stack);
	}
	else if (stack->arr[1] > stack->arr[2])
		rrotate(stack);
}

static void	sort_4_5(t_stack *a, t_stack *b)
{
	int	tmp;

	push(a, b);
	push(a, b);
	if (a->size == 2)
		sort_2(a);
	else
		sort_3(a);
	while (b->size)
	{
		tmp = get_next_min(b->arr[0], a);
		if (tmp == -1)
			move_up(get_min(a), a);
		else
			move_up(tmp, a);
		push(b, a);
	}
	tmp = get_min(a);
	move_up(tmp, a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else
		sort_4_5(a, b);
}
