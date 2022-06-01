# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omanie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 17:25:54 by omanie            #+#    #+#              #
#    Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, obj/%.o, $(SRCS))

OBJ_DIR	=	obj/

FLAGS	=	-Wall -Werror -Wextra

HEADER	=	philo.h

CC			=	gcc

.PHONY		:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ_DIR)	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

obj/%.o		:	%.c $(HEADER) 
			$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)	:
			mkdir -p $@

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean	all
