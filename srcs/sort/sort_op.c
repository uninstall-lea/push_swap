/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:17:53 by lbisson           #+#    #+#             */
/*   Updated: 2022/05/16 18:45:25 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = *stack->arr;
	*stack->arr = *(stack->arr + 1);
	*(stack->arr + 1) = tmp;
	if (stack->which_one == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	push(t_stack *src, t_stack *dest)
{
	int	i;

	i = dest->size + 1;
	while (--i > 0)
		dest->arr[i] = dest->arr[i - 1];
	*(dest->arr) = *(src->arr);
	src->size--;
	dest->size++;
	i = -1;
	while (++i < src->size)
		src->arr[i] = src->arr[i + 1];
	if (dest->which_one == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	rotate(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		ft_swap(&stack->arr[i], &stack->arr[i + 1]);
		i++;
	}
	if (stack->which_one == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rrotate(t_stack *stack)
{
	int	i;

	i = stack->size;
	while (--i > 0)
		ft_swap(&stack->arr[i], &stack->arr[i - 1]);
	if (stack->which_one == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	rotate_both(t_stack *stack1, t_stack *stack2)
{
	int	i;

	i = 0;
	while (i < stack1->size - 1)
	{
		ft_swap(&stack1->arr[i], &stack1->arr[i + 1]);
		i++;
	}
	i = 0;
	while (i < stack2->size - 1)
	{
		ft_swap(&stack2->arr[i], &stack2->arr[i + 1]);
		i++;
	}
	write(1, "rr\n", 3);
}
