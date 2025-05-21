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
	size_t			index;
	int				push_cost;
	bool			under_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

//utilities_nodes
void	append_node(t_node **root, int value);
void	print_list(t_node **root, char stack);
void	free_stack(t_node **root);
int		init_stack_a(t_node **root, char **argv);
int		index_max(t_node **root);
t_node	*value_max(t_node **root);

// Utilities_convert
char	**split_str(char *str, char sep);
void	free_split(char **arr);

// Utilities_errors
bool	validate_str(const char *str);
bool	exist_in_list(t_node *root, int num);
void	handle_error(t_node **root, char **argv);

// Utilities_atol
long	ft_atol(const char *str);

// Utilities_sorted
int		is_sorted(t_node **root);
size_t	len_stack(t_node **root);

// Utilities swap
void	swap(t_node **root);

// Utilities_rotate
void	rotate(t_node **root);
t_node	*last_node(t_node **root);

// Utilities reverse rotate
void	reverse_rotate(t_node **root);

// Utilities sort short
void	sort_two(t_node **root, char stack);
void	sort_three(t_node **root, char stack);

// Utilities sort long
void	sort_long(t_node **root_a, t_node **root_b);

// Utilities push
void	push_a(t_node **root_source, t_node **root_dest);
void	push_b(t_node **root_source, t_node **root_dest);

#endif