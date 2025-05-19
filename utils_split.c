/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:46:58 by paulo             #+#    #+#             */
/*   Updated: 2025/05/18 19:24:03 by paulo            ###   ########.fr       */
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

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**fill_words(char **arr, const char *str, char sep)
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
			arr[j] = ft_strndup(str + i, len_word);
			if (!arr[j])
				return (free_split(arr), NULL);
			j++;
			i += len_word;
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**split_str(char *str, char sep)
{
	size_t	words;
	char	**arr;

	if (!str)
		return (NULL);
	words = count_words(str, sep);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	if (!fill_words(arr + 1, str, sep))
		return (NULL);
	return (arr);
}
