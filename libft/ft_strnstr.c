/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:05:53 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/13 18:56:45 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlimit(size_t big_len, size_t len)
{
	size_t	limit;

	if (big_len >= len)
		limit = len;
	if (big_len < len)
		limit = big_len;
	return (limit);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	big_len;
	size_t	little_len;
	size_t	limit;

	if (ft_strlen(little) == 0)
		return ((char *)(big));
	i = 0;
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (little_len > len)
		return (NULL);
	limit = ft_getlimit(big_len, len);
	while (i < limit && little_len <= limit - i)
	{
		if (big[i] == little[0])
		{
			if (0 == ft_strncmp(&big[i], little, little_len))
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
