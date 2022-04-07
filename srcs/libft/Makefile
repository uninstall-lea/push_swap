# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbisson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 14:47:59 by lbisson           #+#    #+#              #
#    Updated: 2021/12/01 05:29:09 by lbisson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = 	-Wall -Wextra -Werror -I.
EXEC = 		libft.a

SRCS = 		ft_atoi.c 		\
			ft_bzero.c 		\
			ft_calloc.c 	\
			ft_free.c 		\
			ft_isdigit.c 	\
			ft_memcpy.c 	\
			ft_memset.c 	\
			ft_strchr.c 	\
			ft_strdup.c 	\
			ft_strlcpy.c 	\
			ft_strlen.c 	\
			ft_substr.c 	\

OBJS = 		${SRCS:.c=.o}

all: 		${EXEC}

$(EXEC): 	$(OBJS)
			ar rcs ${EXEC} ${OBJS}

clean:
			rm -f ${OBJS}

fclean: 	clean
			rm -f ${EXEC}

re: 		fclean all

.PHONY: 	all bonus clean fclean re
