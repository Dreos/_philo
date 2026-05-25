NAME		=	philo
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror #-fsanitize=thread
INC			=	-I ./inc
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/init.c  \
				src/parsing.c \
				src/philo.c \
				src/utils2.c \
				src/clean.c \
				src/utils.c \
				src/routine.c \
				src/check_routine.c 

all:		obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)
obj:	
	@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			rm -rf $(OBJ) obj

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
