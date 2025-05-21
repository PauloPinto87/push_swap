/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:18:59 by paulo             #+#    #+#             */
/*   Updated: 2025/05/18 19:41:22 by paulo            ###   ########.fr       */
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
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split_str(argv[1], ' ');
	init_stack_a(&stack_a, argv + 1);
	if (!is_sorted(&stack_a))
	{
		if (len_stack(&stack_a) == 2)
			sort_two(&stack_a, 'a');
		else if (len_stack(&stack_a) == 3)
			sort_three(&stack_a, 'a');
		else
			sort_long(&stack_a, &stack_b);
	}
	//printf("Length of stack: %d\n", len_stack(&stack_a));
	return (0);
}
