/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:05:54 by lbisson           #+#    #+#             */
/*   Updated: 2022/03/04 19:29:55 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/push_swap.h"
# include <stdio.h>

t_stack	if_one_arg(int ac, char **av)
{
	int		i;
	char	**stock_args;
	t_stack	a;

	a.size = 0;
	stock_args = ft_split_args(av[1]);
	while (stock_args[a.size])
		a.size++;
	a.arr = malloc(sizeof(int) * a.size);
	if (!a.arr)
		return (a);
	i = -1;
	while (++i < a.size)
		a.arr[i] = ft_atoi(stock_args[i]);
	check_error(ac, a.arr, stock_args);
	ft_free(stock_args, i);
	return (a);
}

t_stack	input_to_int_arr(int ac, char **av)
{
	int 	i;
	t_stack a;

	if (ac == 2)
		return (if_one_arg(ac, av));
	a.arr = malloc(sizeof(int) * (ac - 1));
	if (!a.arr)
		return (a);
	i = -1;
	while (++i < ac - 1)
		a.arr[i] = ft_atoi(av[i + 1]);
	check_error(ac, a.arr, av + 1);
	return (a);
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
	t_stack a = input_to_int(ac, av);
	arr_print(ac - 1, a.arr);
	free(a.arr);
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
