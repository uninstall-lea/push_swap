/* Find the first number bigger than to_place to put to_place right before */
int	get_index(t_stack *a, int to_place)
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

int	get_min(t_stack *a)
{
	int i;
	int	min;

	i = 1;
	min = 0;
	while (i < a->size)
	{
		if (a->arr[min] > a->arr[i])
			min = i;
		i++;
	}
	return (min);
}

/* move_up considering if we use ra or rra
before the middle -> ra
after -> rra */
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
