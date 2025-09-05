/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:06:45 by paulo             #+#    #+#             */
/*   Updated: 2025/09/01 10:05:53 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strndup(const char *source, int	len)
{
	int		i;
	char	*new_str;

	if (!source)
		return (NULL);
	new_str = NULL;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = source[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static int	len_sep(char *arg, char sep)
{
	int	len;

	len = 0;
	while (arg[len] && arg[len] != sep)
		len++;
	return (len);
}

static void	add_words(char **split_list, char *arg, char sep, int *word_count)
{
	int	i;
	int	len;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != sep && (i == 0 || arg[i - 1] == sep))
		{
			len = len_sep(arg + i, sep);
			split_list[*word_count] = ft_strndup(arg + i, len);
			(*word_count)++;
			i += len;
		}
		else
			i++;
	}
	//printf("Atualmente foram add %d words\n", *word_count);
}

static char	**malloc_split(int argc, char **argv, char sep)
{
	int		i;
	int		j;
	int		count;
	char	**split_list;

	split_list = NULL;
	count = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != sep && (j == 0 || argv[i][j - 1] == sep))
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (NULL);
	split_list = malloc((count + 1) * sizeof(char *));
	if (!split_list)
		return (NULL);
	return (split_list);
}

void	ft_free_array(char **split_list)
{
	int	i;

	i = 0;
	while (split_list[i] != NULL)
	{
		free(split_list[i]);
		i++;
	}
	free(split_list);
}

char	**split_str_array(int argc, char **argv, char sep)
{
	char	**split_list;
	int		i;
	int		word_count;

	if (argv == NULL)
		return (NULL);
	word_count = 0;
	split_list = malloc_split(argc, argv, sep);
	if (!split_list)
		return NULL;
	i = 1;
	while (i < argc)
	{
		add_words(split_list, argv[i], sep, &word_count);
		i++;
	}
	split_list[word_count] = NULL;
	return (split_list);
}
