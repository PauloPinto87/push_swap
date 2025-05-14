/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:18:59 by paulo             #+#    #+#             */
/*   Updated: 2025/05/14 14:37:34 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	len_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int main(int argc, char **argv) 
{
	t_node	*stack_a;


	stack_a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split_str(argv[1], ' ');
	init_stack_a(&stack_a, argv);
	print_list(&stack_a);
	free_split(argv);
	free_stack(&stack_a);
	return (0);
}
