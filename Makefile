# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Nome do executável
NAME = push_swap

# Comando para remover arquivos
RM = rm -f

# Fontes e objetos
SRC		= push_swap.c push.c rotates_movements.c swap.c utils_atol.c utils_errors.c utils_nodes.c \
		utils_sort_long.c utils_sort_short.c utils_sorted.c utils_split.c
OBJ 	= $(SRC:.c=.o)

# Alvos
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re