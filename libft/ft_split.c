/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:39:54 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/13 18:56:43 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getstringcount(char const *s, char c)
{
	int	string_count;
	int	i;
	int	string_mode;

	string_mode = 1;
	i = 0;
	string_count = 0;
	while (s[i])
	{
		if (s[i] != c && string_mode == 1)
		{
			string_count++;
			string_mode = -1;
		}
		if (s[i] == c && string_mode == -1)
			string_mode = 1;
		i++;
	}
	return (string_count);
}

static char	*ft_copy_row(int start_index, size_t i, const char *s)
{
	char	*word;
	size_t	size_of_word;
	size_t	j;

	size_of_word = i - start_index;
	word = malloc((size_of_word + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	j = 0;
	while (j < size_of_word)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_freememory(char **splitstr, size_t row)
{
	size_t	i;

	i = 0;
	while (splitstr[i] != NULL && i < row)
	{
		free(splitstr[i]);
		i++;
	}
	free(splitstr);
	return (NULL);
}

static char	**ft_interate_and_split(const char *s, char c, char **splitstr)
{
	size_t	i;
	int		start_index;
	size_t	row;

	i = 0;
	row = 0;
	start_index = -1;
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c || i == ft_strlen(s)) && start_index >= 0)
		{
			splitstr[row] = ft_copy_row(start_index, i, &s[start_index]);
			if (splitstr[row] == NULL)
				return (ft_freememory(splitstr, row));
			row++;
			start_index = -1;
		}
		if (s[i] != c && start_index == -1)
			start_index = i;
		i++;
	}
	splitstr[row] = 0;
	return (splitstr);
}

char	**ft_split(char const *s, char c)
{
	char	**splitstr;
	int		string_count;

	if (s == NULL)
		return (NULL);
	string_count = ft_getstringcount(s, c);
	splitstr = (char **)malloc((string_count + 1) * sizeof(char *));
	if (splitstr == NULL)
		return (NULL);
	return (ft_interate_and_split(s, c, splitstr));
}
