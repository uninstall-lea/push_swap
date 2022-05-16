# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbisson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 15:01:37 by lbisson           #+#    #+#              #
#    Updated: 2022/05/16 18:43:22 by lbisson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH =	srcs/libft/
CFLAGS =	-Wall -Wextra -Werror -g -I.
NAME =		push_swap
LIB =		libft.a

SRCS =		srcs/push_swap.c			\
			srcs/init/check_error.c		\
			srcs/init/init_arr.c		\
			srcs/init/init_chunk.c		\
			srcs/init/init_split.c		\
			srcs/init/init_stack.c		\
			srcs/sort/sort_big.c		\
			srcs/sort/sort_op.c			\
			srcs/sort/sort_small.c		\
			srcs/utils/free.c			\
			srcs/utils/utils_index.c	\
			srcs/utils/utils_sort.c		\

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBPATH)
			gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBPATH)$(LIB)

clean:
			rm -f $(OBJS)
			make -C $(LIBPATH) clean

fclean:		clean
			rm -f $(NAME)
			make -C $(LIBPATH) fclean

re:			fclean all

.PHONY:		all clean fclean re
