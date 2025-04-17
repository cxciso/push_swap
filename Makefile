NAME = push_swap
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRC = main.c push_swap.c parsing.c utils_stack.c moves.c indexation.c radix.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re
