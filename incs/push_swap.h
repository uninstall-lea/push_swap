/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:56:30 by lbisson           #+#    #+#             */
/*   Updated: 2022/02/28 18:28:28 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include <limits.h>
# include <stdio.h>

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
void	check_nargs(int ac);
void	check_error(int to_free_or_not_to_free, char **av, t_stack *a, t_stack *b);

/* INIT */
char	**split_args(char const *s);

/* SORT OPERATIONS */
void	swap(t_stack *a);
void	ft_swap(int *a, int *b);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	push(t_stack *stack1, t_stack *stack2);

/* UTILS */
int		get_min(t_stack *stack);
int		get_next_min(int to_place, t_stack *stack);
int		get_index(int value_searched, t_stack *stack);
void	move_up(int index, t_stack *stack);
void	arr_print(t_stack *a, t_stack *b);
void	free_stacks(t_stack *a, t_stack *b);

/* SORT ALGO */
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

#endif
