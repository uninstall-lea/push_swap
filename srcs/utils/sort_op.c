/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:17:53 by lbisson           #+#    #+#             */
/*   Updated: 2022/03/07 17:52:44 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_swap(int *n)
{
	int	tmp;

	tmp = *n;
	*n = *(n + 1);
	*(n + 1) = tmp;
}

void	ft_swap_both(int *a, int *b)
{
	ft_swap(a);
	ft_swap(b);
}

void	push(t_stack *stack1, t_stack *stack2)
{
	int	i;

	i = stack2->size+1;
	while (--i > 0)
		stack2->arr[i] = stack2->arr[i - 1];
	*(stack2->arr) = *(stack1->arr);
	stack1->size--;
	stack2->size++;
	i = -1;
	while (++i < stack1->size)
		stack1->arr[i] = stack1->arr[i + 1];
}

void	rotate(int *stack, int size)
{
	int	i;
	int tmp;

	i = 0;
	tmp = stack[i];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
}

void	rotate_both(int *stack1, int *stack2, int size)
{
	rotate(stack1, size);
	rotate(stack2, size);
}

void	rrotate(int *stack, int size)
{
	int tmp;

	tmp = stack[size - 1];
	while (--size > 0)
		stack[size] = stack[size - 1];
	stack[0] = tmp;
}

void	rrotate_both(int *stack1, int *stack2, int size)
{
	rrotate(stack1, size);
	rrotate(stack2, size);
}
