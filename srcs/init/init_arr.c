/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:23:38 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/02 05:14:26 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	sort_int_arr(int size, int *arr)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			ft_swap(&arr[i], &arr[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	return ;
}

/* create int arr with all stack_a value, sort it en then use it for chunks */
int	*init_arr(t_stack *a)
{
	int	*arr;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	ft_memcpy(arr, a->arr, sizeof(int) * a->size);
	sort_int_arr(a->size, arr);
	return (arr);
}
