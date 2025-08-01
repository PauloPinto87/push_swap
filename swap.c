/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:30:49 by marvin            #+#    #+#             */
/*   Updated: 2025/08/01 20:30:15 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **root)
{
	t_node	*first;
	t_node	*second;

	if (root == NULL || *root == NULL || (*root)->next == NULL)
		return ;
	first = *root;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*root = second;
}
