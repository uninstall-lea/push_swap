/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:05:54 by lbisson           #+#    #+#             */
/*   Updated: 2022/05/16 18:50:49 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void	if_one_arg(char **av, t_stack *a, t_stack *b)
{
	int		i;
	char	**stock_args;

	a->size = 0;
	b->size = 0;
	a->which_one = 'a';
	b->which_one = 'b';
	stock_args = init_split(av[1]);
	while (stock_args[a->size])
		a->size++;
	a->arr = malloc(sizeof(int) * a->size);
	b->arr = malloc(sizeof(int) * a->size);
	if (!a->arr || !b->arr)
		free_stacks(a, b);
	i = -1;
	while (++i < a->size)
		a->arr[i] = ft_atoi(stock_args[i]);
	check_error(1, stock_args, a, b);
	free_split(stock_args);
}

void	init_stack(int ac, char **av, t_stack *a, t_stack *b)
{
	int	i;

	if (ac == 2)
	{
		if_one_arg(av, a, b);
		return ;
	}
	a->arr = malloc(sizeof(int) * (ac - 1));
	b->arr = malloc(sizeof(int) * (ac - 1));
	a->size = ac - 1;
	b->size = 0;
	a->which_one = 'a';
	b->which_one = 'b';
	if (!a->arr || !b->arr)
		free_stacks(a, b);
	i = -1;
	while (++i < a->size)
		a->arr[i] = ft_atoi(av[i + 1]);
	check_error(0, av + 1, a, b);
}
