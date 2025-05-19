/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:41:51 by paulo             #+#    #+#             */
/*   Updated: 2025/05/16 11:33:58 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **root)
{
	t_node	*curr;

	if (*root == NULL)
		return (1);
	curr = *root;
	while (curr->next != NULL)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

size_t	len_stack(t_node **root)
{
	t_node	*curr;
	size_t	i;
	
	i = 0;
	if (*root == NULL)
		return (i);
	curr = *root;
	while (curr->next != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}