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
int	*arr_init(t_stack *a)
{
	int	*arr;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	ft_memcpy(arr, a->arr, sizeof(int) * a->size);
	sort_int_arr(a->size, arr);
	return (arr);
}

/* we know 500 = 8 chunks, 100 = 3 chunks */
/* between 100 & 500 we have add 5 chunks */
/* it's about 1 chunk every 80 numbers */
void	nb_chunks(int nb_values, t_chunk *chunk)
{
	if (nb_values <= 100)
		chunk->n_chunks = 3;
	if (nb_values > 100)
		chunk->n_chunks = (3 + ((nb_values - 100) / 80));
	return ;
}

void	chunk_size(int nb_values, t_chunk *chunk)
{
	chunk->range = nb_values / chunk->n_chunks;
}

void	init_chunk(int index, int size, int *arr, t_chunk *chunk)
{	
	if (index == chunk->n_chunks - 1)
	{
		nb_chunks(size, chunk);
		chunk_size(size, chunk);
	}
	chunk->min = arr[index * chunk->range];
	if (index == chunk->n_chunks - 1)
		chunk->max = arr[size - 1];
	else
		chunk->max = arr[((index + 1) * chunk->range - 1)];
}

static void push_chunk(int size, t_chunk chunk, t_stack *src, t_stack *dest)
{
	int	i;

	i = 0;
		while (i < size)
		{
			if (src->arr[0] >= chunk.min && src->arr[0] <= chunk.max)
				push(src, dest);
			else
				rotate(src);
			i++;
		}
}

static void	push_back(int range, t_stack *src, t_stack *dest)
{
	int	min;
	int closest;

	while (src->size)
		{
			min = get_min(src);
			closest = calcul_moves(range, src);
			move_up(closest, src);
			push(src, dest);
			if (min == closest)
				rotate(dest);
		}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
	int		*a_arr_sort;
	t_chunk	chunk;
	
	a_arr_sort = arr_init(a);
	if (!a_arr_sort)
		free_stacks(a, b);
	nb_chunks(a->size, &chunk);
	i = chunk.n_chunks;
	while (--i >= 0)
	{
		init_chunk(i, a->size, a_arr_sort, &chunk);
		push_chunk(a->size, chunk, a, b);
		push_back(chunk.range, b, a);
		move_up(get_max(a) + 1, a);
	}
	free(a_arr_sort);
}