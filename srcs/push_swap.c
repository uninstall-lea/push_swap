/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:05:54 by lbisson           #+#    #+#             */
/*   Updated: 2022/03/01 18:34:15 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	input_to_int(int ac, char **av)
{
	int i;
	t_stack a;

	if (ac == 1)
		return (0);
	a.arr = malloc(sizeof(t_stack) * (ac - 1));
	if (!a.arr)
		return (a);
	i = -1;
	while (++i < ac - 1)
		a.arr[i] = ft_atoi(av[i]);
	check_duplicate(ac - 1, a.arr);
	check_int_range(a.arr, av);
	return (a);
}

void	check_int_range(int *arr, char **av)
{
	int				i;
	long long int	big_num;

	i = 1;
	while (av[i])
	{
		big_num = ft_atoll(av[i++])
		if (big_num < INT_MIN || big_num > INT_MAX)
		{	
			ft_printf("Error\n");
			free(a.arr);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_duplicate(int size, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (arr[i + j])
		{
			if (arr[i] == arr[i + j])
			{
				ft_printf("Error\n");
				free(a.arr);
				exit(EXIT_FAILURE);
			}	
			j++;
		}
		i++;
	}
}

void	check_input(int ac, char **av)
{
	int	i;
	int j;

	if (ac == 0)
	{
		ft_printf("Error\n");
		free(a.arr);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				ft_printf("Error\n");
				free(a.arr);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
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
