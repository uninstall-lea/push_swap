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
	ft_memcpy(arr, a->arr, sizeof(int) * a->size);
	sort_int_arr(arr, a->size);
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
	printf("hoho %d / %d = %d\n", nb_values, chunk->n_chunks, 5);
	//printf("%d / %d = %d\n", nb_values, nb_chunks, nb_values / nb_chunks);
}

void	init_chunk(int index, int *arr, t_chunk *chunk)
{	
	chunk->min = arr[index];
	chunk->max = arr[index + (chunk->range)];
	printf("min %d = / max = %d\n", chunk->min, chunk->max);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		i;
//	int		index;
	int		*a_arr_sort;
	t_chunk	chunk;
	
	nb_chunks(a->size, &chunk);
	chunk_size(a->size, &chunk);
	a_arr_sort = arr_init(a);
	if (!a_arr_sort)
		free_stacks(a, b);
	i = 0;
	while (i < a->size - 1)
	{
		init_chunk(i, a_arr_sort, &chunk);
		while (a_arr_sort[i] < chunk.max)
		{
			printf("a_arr_sort[i] = %d / chunk_max = %d\n", a_arr_sort[i], chunk.max);
			if (a->arr[i] >= chunk.min && a->arr[i] <= chunk.max)
			{
				printf("oui\n");
				move_up(a, get_index(i, a));
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
	free(a_arr_sort);
}
