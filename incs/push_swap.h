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

# include "../ps_lib/ps_lib.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void		check_error(int ac, int *arr, char **av);

typedef enum {false, true} t_bool;
typedef struct s_stack
{
	int *arr;
}				t_stack;

#endif
