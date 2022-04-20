#1 find smallest number
#2 move it at top of stack A
#3 Push it to B
#4 repeat until emptying A

/* we know 500 = 22 chunks, 100 = 5 chunks */
/* between 100 & 500 we have add 6 chunks */
/* it's about 1 chunk every 66 numbers */
int	nb_chunk(int nb_number)
{
	if (nb_numberr > 100)
		return (5 + ((nb_number - 100) / 66));
}

int	chunk_size(int nb_number, int nb_chunk)
{
	return (nb_number / nb_chunk);
}

/* create int arr with all stack a value, sort it en then use it for chunks */
/* cheat code++ */

void	tab_init(t_stack *a)
{
	int	*tab;

	tab = malloc(sizeof(int) * a->size);
}

void	sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	tmp;
	int	min_value;
	int	max_value;
	
	min_value = get_min(a);
	max_value = chunk_size(a->size, nb_chunk(a->size));
	while (min_value 
}
