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

	i = stack1->size + 1;
	while (--i > 0)
		stack2[i] = stack2[i - 1];
	*stack2 = *stack1;
	stack1->size--;
	stack2->size++;
	i = -1;
	while (++i < stack1->size)
		stack1[i] = stack1[i + 1];
}

void	rotate(int *stack, size_t size)
{
	int	i;

	i = -1;
	while (++i < size)
		stack[i] = stack[i + 1];
}

void	rotate_both(int *stack1, int *stack2, size_t size)
{
	rotate(stack1, size);
	rotate(stack2, size);
}

void	rrotate(int *stack, size_t size)
{
	size += 1;
	while (--size > 0)
		stack[size] = stack[size - 1];
}

void	rrotate_both(int *stack1, int *stack2, size_t size)
{
	rrotate(stack1, size);
	rrotate(stack2, size);
}
