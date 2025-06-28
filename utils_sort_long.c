/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:27:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 12:27:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index_median(t_node **root)
{
	t_node		*curr;
	size_t		i;
	size_t		median;

	if (*root == NULL)
		return ;
	if (len_stack(root) % 2 == 0)
		median = len_stack(root) / 2;
	else
		median = (len_stack(root) / 2) + 1;
	printf("len = %u and MEDIAN = %u\n", len_stack(root), median);
	curr = *root;
	i = 0;
	while (curr != NULL)
	{
		curr->index = i;
		if (i < median)
			curr->under_median = false;
		else
			curr->under_median = true;
		i++;
		curr = curr->next;
	}
}

void set_target_node(t_node *root_a, t_node *root_b)
{
	t_node	*curr_b;
	t_node	*target_node;
	long	min_diff;

	while (root_a)
	{
		min_diff = LONG_MIN;
		curr_b = root_b;
		while (curr_b != NULL)
		{
			if (root_a->value > curr_b->value
				&& curr_b->value > min_diff)
			{
				min_diff = curr_b->value;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
			if (min_diff == LONG_MIN)
				root_a->target_node = value_max(&root_b);
			else
				root_a->target_node = target_node;
			//printf("value_a: %d, target_node: %d\n", root_a->value, root_a->target_node->value);
		root_a = root_a->next;
	}
}

void set_cost_move(t_node *root_a, t_node *root_b)
{
	t_node	*curr_a;
	//t_node	*curr_b;
	size_t	len_stack_a;
	size_t	len_stack_b;

	len_stack_a = len_stack(&root_a);
	len_stack_b = len_stack(&root_b);
	curr_a = root_a;
	while (curr_a != NULL)
	{
		if (!curr_a->under_median)
			curr_a->push_cost = curr_a->index;
		else
			curr_a->push_cost =  len_stack_a - curr_a->index;
		if (!curr_a->target_node->under_median)
			curr_a->push_cost += curr_a->target_node->index;
		else
			curr_a->push_cost += len_stack_b - curr_a->target_node->index;
		//printf("curr_a value: %d, cost_move: %u, target value: %d\n", curr_a->value, curr_a->push_cost, curr_a->target_node->value);
		curr_a = curr_a->next;
	}
}

void set_cheapest(t_node *root_node)
{
	t_node	*cheapest_node;
	long	min_cost;

	if (root_node == NULL)
		return ;
	min_cost = LONG_MAX;
	while (root_node != NULL)
	{
		if (root_node->push_cost < min_cost)
		{
			min_cost = root_node->push_cost;
			cheapest_node = root_node;
		}
		root_node->cheapest = false;
		root_node = root_node->next;
	}
	cheapest_node->cheapest = true;
}

t_node *find_cheapest(t_node **root_a, t_node **root_b)
{
	t_node	*cheapest_node;

	cheapest_node = NULL;
	if (*root_a == NULL || *root_b == NULL)
		return (NULL);
	cheapest_node = *root_a;
	while (cheapest_node != NULL && cheapest_node->cheapest == false)
		cheapest_node = cheapest_node->next;
	if (!cheapest_node)
		return (NULL);
	printf("cheapest_node: %d, target_node: %d\n", cheapest_node->value, cheapest_node->target_node->value);
	return (cheapest_node);
}

void move_cheapest(t_node **root_a, t_node **root_b)
{
	t_node	*cheapest_node;
	t_node	*target_node;

	cheapest_node = find_cheapest(root_a, root_b);
	if (!cheapest_node)
		return ;
	target_node = cheapest_node->target_node;
    while (*root_a != cheapest_node || *root_b != target_node)
    {
        if (!cheapest_node->under_median && !target_node->under_median
            && *root_a != cheapest_node && *root_b != target_node)
		{
            rotate(root_a, 'a');
			rotate(root_b, 'b');
		}
		else if (cheapest_node->under_median && target_node->under_median
			&& *root_a != cheapest_node && *root_b != target_node)
		{
			reverse_rotate(root_a, 'a');
			reverse_rotate(root_b, 'b');
        }
		else if (cheapest_node->under_median && target_node->under_median
            && *root_a != cheapest_node && *root_b != target_node)
            reverse_rotate(root_a, 'a');
        else if (!cheapest_node->under_median && *root_a != cheapest_node)
            rotate(root_a, 'a');
        else if (cheapest_node->under_median && *root_a != cheapest_node)
            reverse_rotate(root_a, 'a');
        else if (!target_node->under_median && *root_b != target_node)
            rotate(root_b, 'b');
        else if (target_node->under_median && *root_b != target_node)
            reverse_rotate(root_b, 'b');
    }
		push_a(root_a, root_b);
}

void sort_long(t_node **root_a, t_node **root_b)
{
	int		len_a;
	size_t	i;

	len_a = len_stack(root_a);
	i = 0;
	while (len_a > 3 && !is_sorted(root_a) && i < 2)
	{
		push_b(root_a, root_b);
		len_a = len_stack(root_a);
		i++;
	}
	for (int j = 0; j < len_a; j++)
	{
		print_list(root_a, 'a');
		print_list(root_b, 'b');
		set_index_median(root_a);
		set_index_median(root_b);
		set_target_node(*root_a, *root_b);
		set_cost_move(*root_a, *root_b);
		set_cheapest(*root_a);
		move_cheapest(root_a, root_b);
		printf("len_a: %d\n\n", len_stack(root_a));
	}

	print_list(root_a, 'a');
	print_list(root_b, 'b');
	//printf("len_a: %d\n", len_a);
}
