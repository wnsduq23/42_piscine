NAME = bsq

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c utils_print.c map_celltype.c map_read.c map_solve.c map_verify.c map_free.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -IBSQ.h -O2

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

