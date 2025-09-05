/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:30:30 by paulo             #+#    #+#             */
/*   Updated: 2025/09/05 10:50:38 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_node **root, int num)
{
	t_node	*new_node;
	t_node	*current_node;

	current_node = *root;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	current_node->next = new_node;
}

void	print_linked_list(t_node **root)
{
	t_node	*current_node;

	if (*root == NULL)
		return ;
	current_node = *root;
	while (current_node != NULL)
	{
		printf("current_node->num = %d\n", current_node->num);
		current_node = current_node->next;
	}
}

void	ft_free_list(t_node **root)
{
	t_node	*current_node;
	t_node	*next_node;

	if (*root == NULL)
		return ;
	current_node = *root;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}

static void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

void	init_stack_a(char **list_split, t_node **root_a)
{
	int		i;
	long	num;

	i = 0;
	while (list_split[i] != NULL)
	{
		if (!is_valid_num(list_split[i]))
			ft_error();
		num = ft_simple_atoi(list_split[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error();
		if (verify_dup(root_a, num))
			ft_error();
		add_node(root_a, (int)num);
		i++;
	}
}
