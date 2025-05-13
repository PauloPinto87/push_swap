/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validate_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:28:00 by paulo             #+#    #+#             */
/*   Updated: 2025/05/05 12:42:31 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (true);
	return (false);
}

bool    is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool    is_sign(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

bool    validate_str(const char *str)
{
	int     i;
	bool    allow_sign;

	i = 0;
	allow_sign = true;
	while (str[i])
	{
		if (is_space(str[i]))
			allow_sign = true;
		else if (is_sign(str[i]) && allow_sign)
			allow_sign = false;
		else if (is_digit(str[i]))
			allow_sign = false;
		else
			return (false);
		i++;
	}
	return (true);
}