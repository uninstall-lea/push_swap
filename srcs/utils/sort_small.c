void sort_3(t_stack *a)
{
	if (a-> size == 2)
		if (a->arr[0] > a->arr[1])
			ft_swap(a);
	else if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2] 
			&& a->arr[2] > a->arr[0])
		ft_swap(&a.arr);
	else if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2])
		rotate(a, size);
	else if (a->arr[0] > a->arr[1])
	{
		ft_swap(a);
		rrotate(a, size);
	}

	else if (a->arr[1] > a->arr[2] && a->arr[2] > a->arr[0])
	{
		ft_swap(a);
		rotate(a, size);
	}
	else if (a->arr[1] > a->arr[2])
		rrotate(a, size);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	tmp;
	
	if (a->size == 4 || a->size == 5)
	{
		push(a, b);
		push(a, b);
	}
	sort_3(a, size);
	while (b->size) 
	{
		tmp = find_index(a, b->arr[0]);
		if (tmp == -1)
			move_up(a, find_min(a));
		else
			move_up(a, tmp);
		push(b, a);
	}
	tmp = find_min(a);
	move_up(a, tmp);
}
