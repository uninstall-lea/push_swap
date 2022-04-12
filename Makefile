# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbisson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 15:01:37 by lbisson           #+#    #+#              #
#    Updated: 2022/01/14 15:01:39 by lbisson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH =	srcs/libft/
CFLAGS =	-Wall -Wextra -Werror -g -I.
NAME =		push_swap
LIB =		libft.a

SRCS =		srcs/utils/check_error.c	\
			srcs/utils/sort_op.c		\
			srcs/utils/sort_small.c		\
			srcs/utils/split_args.c		\
			srcs/utils/stack_init.c		\
			srcs/utils/utils.c			\

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
