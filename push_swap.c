/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:54:46 by paulo             #+#    #+#             */
/*   Updated: 2025/08/09 19:34:42 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**list_split;
	int		is_error;

	is_error = 0;

	list_split = NULL;
	if (argc < 2)
		return (1);
	else if (argv[1][0] != '\0')
		list_split = split_str_array(argc, argv, ' ');

	is_error = verify_array_errors(list_split);
	printf("is_error = %d\n", is_error);
}
