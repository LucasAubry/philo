#-----------------------Flags_and_Name---------------------
NAME	=	philo
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -pthread -Iinclude -g -O0

#-L/opt/homebrew/lib 
#------------------------Source-----------------------------

# Sources and objects
FILES = main \
		print_all \
		free_all \
		utils \
		philo_tools \
		get_time \
		new_error/new_error \
		routine	

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix obj/, $(addsuffix .o, $(FILES)))

#------------------------Colors-----------------------------

define generate_random_color
python3 -c "import random; \
print(''.join(['\033[38;5;' + str(random.randint(16, 255)) + 'm' + c + '\033[0m' for c in '$(1)']))"
endef

#------------------------Rules------------------------------

all:	${NAME}

obj:
	mkdir -p obj
	mkdir -p obj/new_error

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): obj ${OBJS}
		@$(call generate_random_color, $(CC) $(CFLAGS) -o $@ $(OBJS))
		@$(CC) $(CFLAGS) -o $(NAME) ${OBJS}

obj/%.o: src/%.c
	@$(call generate_random_color, $(CC) $(CFLAGS) -c $< -o $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}
		rm -rf obj

re:	fclean all

.PHONY: all clean fclean re
