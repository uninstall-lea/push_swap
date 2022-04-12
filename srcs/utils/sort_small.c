#include "../../incs/push_swap.h"

void sort_3(int *arr, int size, t_stack *a, t_stack *b)
{
	if (size == 2)
	{
		if (arr[0] > arr[1])
		{	ft_swap(arr);
			arr_print(a, b);
		}
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] 
			&& arr[2] > arr[0])
	{	
		ft_swap(arr);
		arr_print(a, b);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2])
	{
		rotate(arr, size);
		arr_print(a, b);
	}
	else if (arr[0] > arr[1])
	{
		ft_swap(arr);
		arr_print(a, b);
		rrotate(arr, size);
		arr_print(a, b);
	}
	else if (arr[1] > arr[2] && arr[2] > arr[0])
	{
		ft_swap(arr);
		arr_print(a, b);
		rotate(arr, size);
		arr_print(a, b);
	}
	else if (arr[1] > arr[2])
	{	
		rrotate(arr, size);
		arr_print(a, b);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	tmp;
	
	if (a->size == 4 || a->size == 5)
	{
		push(a, b);
		arr_print(a, b);
		push(a, b);
		arr_print(a, b);
	}
	sort_3(a->arr, a->size, a, b);
	while (b->size) 
	{
		tmp = get_index(a, b->arr[0]);
		if (tmp == -1)
			move_up(a, get_min(a));
		else
			move_up(a, tmp);
		push(b, a);
	}
	tmp = get_min(a);
	move_up(a, tmp);
}
