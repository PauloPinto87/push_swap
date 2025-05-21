/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:12:57 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 10:12:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **root_source, t_node **root_dest)
{
	t_node	*temp;

	if (root_source == NULL || *root_source == NULL || root_dest == NULL)
		return ;
	temp = *root_source;
	*root_source = (*root_source)->next;
	if (*root_source != NULL)
		(*root_source)->prev = NULL;
	temp->next = *root_dest;
	if (*root_dest != NULL)
		(*root_dest)->prev = temp;
	*root_dest = temp;
}

void	push_a(t_node **root_source, t_node **root_dest)
{
	push(root_source, root_dest);
	printf("pa\n");
}

void	push_b(t_node **root_source, t_node **root_dest)
{
	push(root_source, root_dest);
	printf("pb\n");
}
