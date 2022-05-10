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
	int	*arr;
	int	size;
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
void	check_error(char **av, t_stack *a, t_stack *b, int to_free_or_not_to_free);

/* SORT OPERATIONS */
void	ft_swap(int *n);
void	rotate(int *stack, int size);
void	rrotate(int *stack, int size);
void	ft_swap_both(int *a, int *b);
void	rotate_both(int *stack1, int *stack2, int size);
void	rrotate_both(int *stack1, int *stack2, int size);
void	push(t_stack *stack1, t_stack *stack2);

/* UTILITIES */
int		get_min(t_stack *stack);
int		get_next_min(int to_place, t_stack *stack);
int		get_index(int value_searched, t_stack *stack);
void	move_up(int index, t_stack *stack);
void	arr_print(t_stack *a, t_stack *b);
void	free_stacks(t_stack *a, t_stack *b);

/* SORT ALGO */
char	**split_args(char const *s);
void	sort_3(int *arr, int size);
void	sort_5(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

#endif
