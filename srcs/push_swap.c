/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:23:38 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/02 05:14:26 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		exit(EXIT_FAILURE);
	init_stack(ac, av, &a, &b);
	if (!is_sort(&a))
	{	
		if (a.size <= 5)
			sort_small(&a, &b);
		else
			sort_big(&a, &b);
	}
	free(a.arr);
	free(b.arr);
	return (0);
}
