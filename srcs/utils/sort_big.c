#include "../../incs/push_swap.h"

void	sort_int_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			ft_swap(&arr[i]);
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
	ft_memcpy(arr, a->arr, a->size * sizeof(int));
	sort_int_arr(arr, a->size);
	return (arr);
}

/* we know 500 = 22 chunks, 100 = 5 chunks */
/* between 100 & 500 we have add 6 chunks */
/* it's about 1 chunk every 66 numbers */
int	nb_chunks(int nb_values)
{
	if (nb_values > 100)
		return (5 + ((nb_values - 100) / 66));
	return (0);
}

int	chunk_size(int nb_values, int nb_chunks)
{
	return (nb_values / nb_chunks);
}

void	init_chunk(int stack_a_size, int *arr, t_chunk *chunk)
{
	int	range;

	chunk->min = arr[0];
	range = chunk_size(stack_a_size, nb_chunks(stack_a_size));
	chunk->max = arr[range];

}

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
//	int		index;
	int		*a_arr_sort;
	t_chunk	chunk;
	
	a_arr_sort = arr_init(a);
	if (!a_arr_sort)
		return ;
	i = 0;
	while (i < a->size)
	{
		init_chunk(a->size, a_arr_sort, &chunk);
		while (a_arr_sort[i] < chunk.max)
		{
			if (a->arr[i] >= chunk.min && a->arr[i] <= chunk.max)
			{
				move_up(a, i);
				push(a, b);
			}
			else
				i++;
		}
		/*while (chunk.min < chunk.max)
		{
			index = get_index(b, chunk.min);
			move_up(b, index);
			chunk.min = get_next_min(b, chunk.min);
		}
		*/
	}
}
