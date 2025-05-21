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


void	reverse_rotate(t_node **root)
{
	t_node	*first;
	t_node	*last;

	if (*root == NULL || (*root)->next == NULL)
		return ;
	first = *root;
	last = last_node(root);
	*root = last;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next->next = NULL;
}
