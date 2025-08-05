/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:46:58 by paulo             #+#    #+#             */
/*   Updated: 2025/08/05 15:44:17 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char *str, char sep)
{
	size_t	qnt_words;
	size_t	i;

	qnt_words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
		{
			qnt_words++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (qnt_words);
}

static char	*ft_strndup(const char *str, size_t len)
{
	char	*copy;
	size_t	i;

	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**fill_words(char **new_array, const char *str, char sep)
{
	size_t	i;
	size_t	j;
	size_t	len_word;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		len_word = 0;
		while (str[i + len_word] && str[i + len_word] != sep)
			len_word++;
		if (len_word > 0)
		{
			new_array[j] = ft_strndup(str + i, len_word);
			if (!new_array[j])
				return (free_split(new_array), NULL);
			j++;
			i += len_word;
		}
	}
	new_array[j] = NULL;
	return (new_array);
}

char	**split_str(char *str, char sep)
{
	size_t	words;
	char	**new_array;

	if (!str)
		return (NULL);
	words = count_words(str, sep);
	new_array = malloc(sizeof(char *) * (words + 1));
	if (!new_array)
		return (NULL);
	if (!fill_words(new_array, str, sep))
		return (NULL);
	return (new_array);
}
