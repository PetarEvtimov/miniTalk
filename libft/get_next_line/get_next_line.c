/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:46:38 by pevtimov          #+#    #+#             */
/*   Updated: 2024/03/06 20:58:02 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	size_t			s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (s_len - start < len)
		len = s_len - start;
	substr = ft_calloc(sizeof(char), len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = (char *)ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result != NULL)
	{
		i = 0;
		while (*s1)
		{
			result[i] = *s1;
			s1++;
			i++;
		}
		while (*s2)
		{
			result[i] = *s2;
			s2++;
			i++;
		}
	}
	return (result);
}

char	*extract_n_store(char *old_storage)
{
	char	*storage;
	size_t	i;

	i = 0;
	while (old_storage[i] != '\0' && old_storage[i] != '\n')
		i++;
	if (old_storage[i] == 0)
		return (NULL);
	storage = ft_substr(old_storage, i + 1, ft_strlen(old_storage) - i);
	if (*storage == 0)
	{
		free(storage);
		storage = NULL;
	}
	old_storage[i + 1] = 0;
	return (storage);
}

char	*read_n_get_line(int fd, char *storage, char *buff)
{
	ssize_t	bytes_read;
	char	*temp_storage;

	while (1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = 0;
		if (bytes_read == -1)
		{
			free(storage);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		if (!storage)
			storage = ft_strdup_mod("");
		temp_storage = storage;
		storage = ft_strjoin(temp_storage, buff);
		free(temp_storage);
		temp_storage = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	line = read_n_get_line(fd, storage, buff);
	free (buff);
	buff = NULL;
	if (!line)
		return (NULL);
	storage = extract_n_store(line);
	return (line);
}
