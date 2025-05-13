/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:18:59 by paulo             #+#    #+#             */
/*   Updated: 2025/05/12 15:52:29 by paulo            ###   ########.fr       */
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
	char	**args;
	//t_node  *a;
	//t_node  *b;

	//a = NULL;
	//b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		args = split_str(argv[1], ' ');
		if (!args)
			return (1);
		printf("Number of args is %ld\n", len_args(args));
		free_split(args);
	}
}
