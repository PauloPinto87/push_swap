/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:56:34 by paulo             #+#    #+#             */
/*   Updated: 2025/08/09 19:47:25 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(char character)
{
	return (character >= '0' && character <= '9');
}

static int	ft_issignal(char character)
{
	return (character == '-' || character == '+');
}

int	verify_array_errors(char **split_list)
{
	int	i;
	int	j;

	i = 0;
	while (split_list[i] != NULL)
	{
		j = 0;
		while (split_list[i][j])
		{
			if (ft_issignal(split_list[i][j]) || ft_isdigit(split_list[i][j]))
				printf("Eh digito ou signal\n");
			else
				printf("Eh qualquer outra coisa\n");
			j++;
		}
		i++;
	}

	return (0);
}