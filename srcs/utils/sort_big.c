#include "../../incs/push_swap.h"

void	sort_int_arr(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] > stack->arr[i + 1])
		{
			ft_swap(&stack->arr[i], &stack->arr[i + 1]);
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
	sort_int_arr(a);
	return (arr);
}

/* we know 500 = 22 chunks, 100 = 5 chunks */
/* between 100 & 500 we have add 6 chunks */
/* it's about 1 chunk every 66 numbers */
void	nb_chunks(int nb_values, t_chunk *chunk)
{
	if (nb_values == 100)
		chunk->n_chunks = 5;
	if (nb_values > 100)
		chunk->n_chunks = (5 + ((nb_values - 100) / 66));
	return ;
}

void	chunk_size(int nb_values, t_chunk *chunk)
{
	chunk->range = nb_values / chunk->n_chunks;
	printf("chunk range : %d\n", chunk->range);
}

void	init_chunk(int index, int size, int *arr, t_chunk *chunk)
{	
	if (index == 0)
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

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		size_cpy;
	int		*a_arr_sort;
	t_chunk	chunk;
	
	a_arr_sort = arr_init(a);
	if (!a_arr_sort)
		free_stacks(a, b);
	i = 0;
	size_cpy = a->size;
	while (i < chunk.n_chunks)
	{
		j = 0;
		init_chunk(i, size_cpy, a_arr_sort, &chunk);
		while (j < size_cpy)
		{
			if (a->arr[0] >= chunk.min && a->arr[0] <= chunk.max)
				push(a, b);
			else
				rotate(a);
			j++;
		}
		while (b->size)
		{
			move_up(get_min(b), b);
			push(b, a);
			rotate(a);
		}
		i++;
	}
	free(a_arr_sort);
}