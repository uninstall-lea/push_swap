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

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define WHITESPACES " \t\n\v\f\r"

typedef enum {false, true} t_bool;
typedef struct s_stack
{
	int *arr;
	size_t	size;
}				t_stack;

/* ERROR */
void		check_error(int ac, int *arr, char **av);

/* SORT OPERATIONS */
void	ft_swap(int *n);
void	rotate(int *stack, size_t size);
void	rrotate(int *stack, size_t size);
void	push(t_stack *stack1, t_stack *stack2);
void	ft_swap_both(int *a, int *b);
void	rotate_both(int *stack1, int *stack2, size_t size);
void	rrotate_both(int *stack1, int *stack2, size_t size);

/* UTILITIES */
int		get_min(t_stack *a);
int		get_index(t_stack *a, int to_place);
void	move_up(t_stack *a, int index);

/* SORT ALGO */
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

#endif
