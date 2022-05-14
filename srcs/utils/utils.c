#include "../../incs/push_swap.h"

void	free_stacks(t_stack *a, t_stack *b)
{
	free((free(a), b));
	exit(EXIT_FAILURE);
}

/* if not used, delete */
int	get_index(int value_searched, t_stack *stack)
{
	int	index;

	index = 0;
	while (index < stack->size && stack->arr[index] != value_searched)
		index++;
	return (index);
}

/* Find the first number bigger than to_place to put to_place right before */
int	get_next_min(int to_place, t_stack *stack)
{
	int i;
	int index;

	i = 0;
	index = -1;
	while (i < stack->size)
	{
		if (stack->arr[i] > to_place)
			if (index == -1 || stack->arr[i] < stack->arr[index])
				index = i;
		i++;
	}
	return (index);
}

int	get_min(t_stack *stack)
{
	int i;
	int	min;

	i = 1;
	min = 0;
	while (i < stack->size)
	{
		if (stack->arr[min] > stack->arr[i])
			min = i;
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > stack->arr[max])
			max = i;
		i++;
	}
	return (max);
}

static int	get_nb_moves(int i, int range)
{
	if (i < range / 2)
		return (i);
	return (range - i);
}

int calcul_moves(int range, t_stack *b)
{
	int	i_min;
	int	i_max;

	i_min = get_min(b);
	i_max = get_max(b);
	if (get_nb_moves(i_min, range) < get_nb_moves(i_max, range))
		return (i_min);
	return (i_max);	
}

/* move_up considering if we use ra or rra
before the middle -> ra
after -> rra */
void	move_up(int index, t_stack *stack)
{
	if (index < stack->size / 2)
		while (index)
		{
			rotate(stack);
			index--;
		}
	else
		while (index < stack->size)
		{
			rrotate(stack);
			index++;
		}
}
