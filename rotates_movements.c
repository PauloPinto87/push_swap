/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:30:49 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 12:30:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*last_node(t_node **root)
{
	t_node	*curr;

	if (*root == NULL)
		return (NULL);
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

void rotate(t_node **root, char stack)
{
	t_node *first;
	t_node *second;

	if (!*root || !(*root)->next)
		return;
	
	first = *root;
	second = first->next;
	
	// Encontra o último nó
	t_node *last = first;
	while (last->next)
		last = last->next;
	
	// Atualiza links
	*root = second;
	second->prev = NULL;  // Corrige o ponteiro prev do novo root
	
	// Move o primeiro nó para o final
	last->next = first;
	first->prev = last;   // Mantém a consistência duplamente ligada
	first->next = NULL;
	
	// Imprime a operação
	printf("r%c\n", stack);
}
void	reverse_rotate(t_node **root, char stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*before_last;

	if (*root == NULL || (*root)->next == NULL)
		return ;
	first = *root;
	last = last_node(root);
	before_last = last->prev;

	first->prev = last;
	last->prev = NULL;
	last->next = first;
	before_last->next = NULL;
	*root = last;
	if (stack == 'a')
		printf("rra\n");
	else if (stack == 'b')
		printf("rrb\n");
}

