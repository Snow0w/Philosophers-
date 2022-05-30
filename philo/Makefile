NAME	=	philo

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, obj/%.o, $(SRCS))

OBJ_DIR	=	obj/

FLAGS	=	-Wall -Werror -Wextra

FLAGS	+=	 -fsanitize=thread

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
