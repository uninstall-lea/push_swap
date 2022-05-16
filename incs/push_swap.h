/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:56:30 by lbisson           #+#    #+#             */
/*   Updated: 2022/05/16 18:42:59 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include <limits.h>

# define WHITESPACES " \t\n\v\f\r"
# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int		*arr;
	int		size;
	char	which_one;
}			t_stack;

typedef struct s_chunk
{
	int	min;
	int	max;
	int	range;
	int	n_chunks;
}			t_chunk;

/* ERROR */
int		is_sort(t_stack *a);
void	check_error(int to_free_or_not_to_free, char **av,
			t_stack *a, t_stack *b);

/* INIT */
int		*init_arr(t_stack *a);
char	**init_split(char const *s);
void	init_stack(int ac, char **av, t_stack *a, t_stack *b);
void	nb_chunks(int nb_values, t_chunk *chunk);
void	init_chunk(int index, int size, int *arr, t_chunk *chunk);

/* SORT ALGO */
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

/* SORT OPERATIONS */
void	swap(t_stack *a);
void	ft_swap(int *a, int *b);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate_both(t_stack *stack1, t_stack *stack2);

/* UTILS */
/* index */
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_next_min(int to_place, t_stack *stack);
/* free */
void	free_split(char **str);
void	free_stacks(t_stack *a, t_stack *b);
/* sort */
int		calcul_moves(int range, t_stack *b);
void	move_up(int index, t_stack *stack);

#endif
