/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:28:00 by paulo             #+#    #+#             */
/*   Updated: 2025/05/14 13:47:42 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    validate_str(const char *str)
{
	int     i;
	bool    allow_sign;

	i = 0;
	allow_sign = true;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			allow_sign = true;
		else if ((str[i] == '+' || str[i] == '-') && allow_sign)
			allow_sign = false;
		else if ((str[i] >= '0' && str[i] <= '9'))
			allow_sign = false;
		else
			return (false);
		i++;
	}
	return (true);
}

bool	exist_in_list(t_node *root, int num)
{
	t_node	*curr;

	if (root == NULL)
		return (false);
	curr = root;
	while (curr != NULL)
	{
		if (curr->value == num)
			return (true);
		curr = curr->next;
	}
	return (false);
}

void handle_error(t_node **root, char **argv)
{
	if (root != NULL)
		free_stack(root);
	if (argv != NULL)
		free_split(argv);
}