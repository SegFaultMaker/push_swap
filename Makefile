NAME = push_swap
BONUS = push_swap
LIBFT = libft.a
SOURCES = ./src/push_swap.c ./src/get_arr.c ./src/get_order.c \
		  ./src/utils.c ./src/stack_utils.c ./src/instructions.c \
		  ./src/hardcode.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	mv *.o src
	$(CC) -o $@ $? $(LIBFT)

$(OBJECTS): $(SOURCES)
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
