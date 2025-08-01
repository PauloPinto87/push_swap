/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:27:06 by marvin            #+#    #+#             */
/*   Updated: 2025/08/01 20:44:39 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **root, char stack)
{
	swap(root);
	printf("s%c\n", stack);
}

void	sort_three(t_node **root, char stack)
{
	int	max_index;

	while (!is_sorted(root))
	{
		max_index = index_max(root);
		if (max_index == 2)
		{
			swap(root);
			printf("s%c\n", stack);
		}
		else if (max_index == 0)
			rotate(root, stack);
		else
			reverse_rotate(root, stack);
	}
}
