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

# include "../incs/push_swap.h"
# include <stdio.h>

void	free_stack(t_stack *a, t_stack *b)
{
	(free(a, free(b));
	exit(EXIT_FAILURE);
}

void	if_one_arg(int ac, char **av, t_stack *a, t_stack *b)
{
	int		i;
	char	**stock_args;

	a->size = 0;
	b->size = 0;
	stock_args = ft_split_args(av[1]);
	while (stock_args[a->size])
		a->size++;
	a->arr = malloc(sizeof(int) * a->size);
	b->arr = malloc(sizeof(int) * a->size);
	if (!a->arr || !b->arr)
		free_stack(a, b);
	i = -1;
	while (++i < a->size)
		a->arr[i] = ft_atoi(stock_args[i]);
	check_error(ac, a->arr, stock_args, 1);
}

void	stack_init(int ac, char **av, t_stack *a, t_stack *b)
{
	int 	i;

	if (ac == 2)
	{
		if_one_arg(ac, av);
		return;
	}
	a->arr = malloc(sizeof(int) * (ac - 1));
	b->arr = malloc(sizeof(int) * (ac - 1));
	a->size = ac - 1;
	b->size = 0;
	if (!a->arr || !b-> arr)
		free_stack(a, b);
	i = -1;
	while (++i < ac - 1)
		a->arr[i] = ft_atoi(av[i + 1]);
	check_error(ac, a->arr, av + 1, 0);
}

void	arr_print(int size, int *arr)
{
	int	i;

	i = 0;
	(void) size;
	while (i <3)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	printf("-----------\n  stack a\n");
}

int	main(int ac, char **av)
{
	t_stack a; 
	t_stack b;
	
	stack_init(ac, av, &a, &b);
	arr_print(ac - 1, a.arr);
	sort_5(a, b);
	arr_print(ac - 1, a.arr);
	free(a.arr);
	free(b.arr);
	return (0);
}

/*t_fptr	dispach(const char *s, char *a, char *b)
{
	size_t		i;
	size_t		index;
	t_fptr		callback[11];
	static char	**rule = {"sa", "sb", "ss", "pa", "pb", "ra",
						"rb", "rr", "rra", "rrb", "rrr",}

	callback[0] = ft_swap(a[0], a[1]);
	callback[1] = ft_swap(b[0], b[1]);
	callback[2] = ft_swap2(a, b);
	callback[3] = ft_push(a, b);
	callback[4] = ft_push(b, a);
	callback[5] = ft_rotate(a);
	callback[6] = ft_rotate(b);
	callback[7] = ft_rotate2(a, b);
	callback[8] = ft_rrotate(a);
	callback[9] = ft_rrotate(b);
	callback[10] = ft_rrotate2(a, b);
	while (rule[i])
	{
		index = ft_strstr(s, rule[i]) - rule;
		if (index >= 0)
			return (callback[index])
		i++;
	}
	return (NULL);
}
*/
