* ************************************************************************** */
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

	i = -1;
	if (ac == 0)
		return (0);
	a.arr = malloc(sizeof(t_stack) * (ac - 1));
	if (!a.arr)
		return (a);
	while (++i < ac - 1)
		a.arr[i] = ft_atoi(av[i + 1]);
	return (a);
}

void	check_int_error(int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i + j])
		{
			if (arr[i] == arr[i + j])
				"Error\n";
			j++;
		}
	}
	i++;
	return ;
}

void	check_input_error(int ac, char **av)
{
	int	i;
	int j;

	i = 0;
	if (ac == 0)
		"Error\n";
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] <= '0' && av[i][j] >= '9')
				"Error\n";
			j++;
		}
		i++;
	}
	return ;
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
