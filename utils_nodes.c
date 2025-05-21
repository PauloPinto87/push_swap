/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:37:13 by paulo             #+#    #+#             */
/*   Updated: 2025/05/18 19:56:50 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->value = value;
	if (*root == NULL)
	{
		*root = new_node;
		new_node->prev = NULL;
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
	new_node->prev = curr;
}

int	init_stack_a(t_node **root, char **argv)
{
	size_t		i;
	long		num;

	i = 0;
	while (argv[i])
	{
		if (!validate_str(argv[i]))
			return (handle_error(root, argv), 0);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (handle_error(root, argv), 0);

		if (exist_in_list(*root, (int)num))
			return (handle_error(root, argv), 0);
		append_node(root, (int)num);
		i++;
	}
	free_split(argv);
	return (1);
}

void 	print_list(t_node **root, char stack)
{
	t_node *curr;

	if (root == NULL || *root == NULL)
	{
		printf("List of nodes stack %c is empty\n", stack);
		return ;
	}
	printf("List of nodes stack %c:\n", stack);
	curr = *root;
	while (curr != NULL)
	{
		printf("value: %d, index: %d, under_median: %d, cheapest: %d, cost_move: %d\n", curr->value, curr->index, curr->under_median, curr->cheapest, curr->push_cost);
		curr = curr->next;
	}
}

void	free_stack(t_node **root)
{
	t_node	*curr;
	t_node	*temp_node;

	if (*root == NULL)
		return ;
	curr = *root;
	while (curr != NULL)
	{
		temp_node = curr->next;
		free(curr);
		curr = temp_node;
	}
	*root = NULL;
}

size_t	len_stack(t_node **root)
{
	t_node	*curr;
	size_t	i;
	
	i = 0;
	if (*root == NULL)
		return (i);
	curr = *root;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int	index_max(t_node **root)
{
	t_node	*curr;
	int		max;
	int		i;
	int		index;

	if (root == NULL || *root == NULL)
		return (-1);
	curr = *root;
	max = curr->value;
	i = 0;
	index = 0;
	while (curr != NULL)
	{
		if (curr->value > max)
		{
			max = curr->value;
			index = i;
		}
		curr = curr->next;
		i++;
	}
	return (index);
}
t_node	*value_max(t_node **root)
{
	t_node	*curr;
	t_node	*max_node;

	if (root == NULL || *root == NULL)
		return (NULL);
	curr = *root;
	max_node = curr;
	while (curr != NULL)
	{
		if (curr->value > max_node->value)
			max_node = curr;
		curr = curr->next;
	}
	return (max_node);
}