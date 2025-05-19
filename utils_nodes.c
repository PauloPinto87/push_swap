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
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	init_stack_a(t_node **root, char **argv)
{
	size_t		i;
	long		num;

	i = 0;
	while (argv[i])
	{
		if (!validate_str(argv[i]))
		{
			printf("String nao convertivel no atol\n");
			return ;
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			printf("Valor convertido maior ou menor que os LIMTIS de int\n");
			return ;
		}
		if (exist_in_list(*root, (int)num))
		{
			printf("Valor ja existe na lista\n");
			return ;
		}	
		append_node(root, (int)num);
		i++;
	}
}

void 	print_list(t_node **root)
{
	t_node *curr;

	if (*root == NULL)
		return ;
	curr = *root;
	while (curr != NULL)
	{
		printf("%d\n", curr->value);
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
