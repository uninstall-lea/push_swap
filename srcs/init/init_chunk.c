/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:05:54 by lbisson           #+#    #+#             */
/*   Updated: 2022/03/04 19:29:55 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

/* we know 500 = 7 chunks, 100 = 4 chunks */
/* between 100 & 500 we have add 5 chunks */
/* it's about 1 chunk every 133 numbers */
void	nb_chunks(int nb_values, t_chunk *chunk)
{
	if (nb_values <= 100)
		chunk->n_chunks = 4;
	if (nb_values > 100)
		chunk->n_chunks = (4 + ((nb_values - 100) / 133));
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
