/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:56:34 by paulo             #+#    #+#             */
/*   Updated: 2025/08/09 19:32:07 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	ft_isdigit(char character)
// {
// 	return (character >= '0' && character <= '9');
// }

// static int	ft_issignal(char character)
// {
// 	return (character == '-' || character == '+');
// }

int	verify_array_errors(char **split_list)
{
	int	i;

	printf("ERRORS\n");
	i = 0;
	while (split_list[i] != NULL)
	{
		printf("split_list[%d] = %s\n", i, split_list[i]);
		i++;
	}

	return (0);
}