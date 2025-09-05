/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:56:50 by paulo             #+#    #+#             */
/*   Updated: 2025/08/31 16:17:41 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_simple_atoi(char *str)
{
	long	result;
	int		signal;

	result = 0;
	signal = 1;
	while (*str != '\0')
	{
		if (*str == '-' || *str == '+' )
		{
			if (*str == '-')
				signal *= -1;
		}
		else
			result = result * 10 + (*str - '0');
		str++;
	}
	return (result * signal);
}