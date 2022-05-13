#include "../../incs/push_swap.h"

void sort_3(int *arr, int size)
{
	if (size == 2)
	{
		if (arr[0] > arr[1])
			ft_swap(arr);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] 
			&& arr[2] > arr[0])
		ft_swap(arr);
	else if (arr[0] > arr[1] && arr[1] < arr[2])
		rotate(arr, size);
	else if (arr[0] > arr[1])
	{
		ft_swap(arr);
		rrotate(arr, size);
	}
	else if (arr[1] > arr[2] && arr[2] > arr[0])
	{
		ft_swap(arr);
		rotate(arr, size);
	}
	else if (arr[1] > arr[2])
		rrotate(arr, size);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	tmp;
	
	if (a->size == 4 || a->size == 5)
	{
		push(a, b);
		push(a, b);
	}
	sort_3(a->arr, a->size);
	while (b->size) 
	{
		tmp = get_next_min(b->arr[0], a);
		if (tmp == -1)
			move_up(get_min(a), a);
		else
			move_up(tmp, a);
		push(b, a);
	}
	tmp = get_min(a);
	move_up(tmp, a);
}

/*
void sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	appeler sort_2 / sort_3 / sort_4 / sort_5
}
*/