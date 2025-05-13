#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <stdlib.h>

typedef int	t_bool;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

//utilities_nodes
void	insert_end(t_node **root, int value);
void 	print_list(t_node **root);

// Utilities_convert
char	**split_str(char *str, char sep);
void	free_split(char **arr);

// Utilities_validate
bool    validate_str(const char *str);

// Utilities_atol
long	ft_atol(const char *str);

#endif