# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Nome do executável
NAME = push_swap 

# Comando para remover arquivos
RM = rm -f

# Fontes e objetos
SRC		= push_swap.c utils_split.c utils_error.c
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