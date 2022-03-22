/* Find the first number bigger than to_place and put to_place right before */
int	find_index(t_stack *a, int to_place)
{
	int i;
	int index;

	i = 0;
	index = -1;
	while (i < a->size)
	{
		if (a->arr[i] > to_place)
			if (ret == -1 || a->arr[i] < a->arr[index])
				ret = i;
		i++;
	}
	return (index);
}

int	find_min(t_stack *a)
{
	int i;
	int	min;

	i = 1;
	min = 0;
	while (i < a->size)
	{
		if (a->arr[min] > a->arr[i])
			ret = i;
		i++;
	}
	return (min);
}

/* move_up considering if we use ra or rra
before the middle would be ra
after would be rra */
void	move_up(t_stack *a, int index)
{
	if (index < a->size / 2)
	{
		while (index)
		{
			rotate(a, a->size);
			index--;
		}
	}
	else
	{
		while (index < a->size)
		{
			rrotate(a, a->size);
			index++;
		}
	}
}

void sort_three(t_stack *a)
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

void	sort_five(t_stack *a, t_stack *b)
{
	int	tmp;

	push(a, b);
	push(a, b);
	if (a->size <= 3)
		sort_three(a, size);
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
