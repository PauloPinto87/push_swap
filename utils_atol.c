/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:52:57 by paulo             #+#    #+#             */
/*   Updated: 2025/08/01 20:28:46 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	num_conv;
	int		i;
	int		signal;

	signal = 1;
	num_conv = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			signal = -1;
		else
			num_conv = num_conv * 10 + (str[i] - '0');
		i++;
	}
	return (num_conv * signal);
}
