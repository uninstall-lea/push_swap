/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:05:54 by lbisson           #+#    #+#             */
/*   Updated: 2022/03/04 19:29:55 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../incs/push_swap.h"

void	if_one_arg(char **av, t_stack *a, t_stack *b)
{
	int		i;
	char	**stock_args;

	a->size = 0;
	b->size = 0;
	stock_args = split_args(av[1]);
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

void	stack_init(int ac, char **av, t_stack *a, t_stack *b)
{
	int 	i;

	if (ac == 2)
	{
		if_one_arg(av, a, b);
		return;
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

void	arr_print(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < a->size || i < b->size)
	{
		if(i < a->size)
			printf("%-14d", a->arr[i]);
		if(i < b->size)
			printf("%-14d", b->arr[i]);
		printf("\n");
		i++;
	}
	printf("-----------   -----------\n stack a       stack b\n");
}

int	main(int ac, char **av)
{
	t_stack a; 
	t_stack b;
	
	check_nargs(ac);
	stack_init(ac, av, &a, &b);
	arr_print(&a, &b);
	if (a.size <= 5)
		sort_small(&a, &b);
	else
		sort_big(&a, &b);
	arr_print(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}