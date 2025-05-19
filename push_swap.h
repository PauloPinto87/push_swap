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
	int				index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

//utilities_nodes
void	append_node(t_node **root, int value);
void 	print_list(t_node **root);
void	free_stack(t_node **root);
void	init_stack_a(t_node **root, char **argv);

// Utilities_convert
char	**split_str(char *str, char sep);
void	free_split(char **arr);

// Utilities_errors
bool    validate_str(const char *str);
bool	exist_in_list(t_node *root, int num);

// Utilities_atol
long	ft_atol(const char *str);

// Utilities_sorted
int		is_sorted(t_node **root);
size_t	len_stack(t_node **root);

#endif