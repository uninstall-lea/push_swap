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
	if (stack2->which_one == 'a')
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
	int i;

	i = stack->size;
	while (--i > 0)
		ft_swap(&stack->arr[i], &stack->arr[i - 1]);
	if (stack->which_one == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}