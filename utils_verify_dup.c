/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verify_dup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:51:16 by paulo             #+#    #+#             */
/*   Updated: 2025/09/05 09:55:56 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_dup(t_node **root, int num)
{
	t_node	*current_node;

	current_node = *root;
	while (current_node != NULL)
	{
		if (num == current_node->num)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}