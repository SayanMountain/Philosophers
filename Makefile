NAME		= 	philo
HEADER		= 	philo

LIST		=  	main.c 							\
				main_utils_1.c					\
				ft_atoi.c 						\
				utils_for_time_1.c				\
				utils_for_life_1.c				\
				pars_arg.c


OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror

%.o:%.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ) $(HEADER)
			gcc $(OBJ) -o $(NAME)

all :		$(NAME)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

debug:
	gcc -g $(LIST) -o $(NAME)

re :		fclean all

.PHONY :	all clean fclean re