NAME = push_swap
BONUS = checker
LIBFT = libft.a
SOURCES = ./src/push_swap.c ./src/get_arr.c ./src/get_order.c \
		  ./src/utils.c ./src/stack_utils.c ./src/instructions.c \
		  ./src/validation.c ./src/hardcode.c
BSOURCES = ./src_bonus/checker.c ./src_bonus/get_arr.c ./src_bonus/instructions.c \
		   ./src_bonus/utils.c ./src_bonus/stack_utils.c ./src_bonus/validation.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS)

$(NAME): $(OBJECTS)
	mv *.o src
	$(CC) $(CFLAGS) -o $@ $? $(LIBFT)

$(BONUS): $(BOBJECTS)
	mv *.o src_bonus
	$(CC) $(CFLAGS) -o $@ $? $(LIBFT)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(CFLAGS) $?

$(BOBJECTS): $(BSOURCES)
	$(CC) -c $(CFLAGS) $?

$(LIBFT):
	make -C ./libft
	cp ./libft/libft.a .
	make -C ./libft fclean

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME) $(BONUS) $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
