/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:28:15 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/13 20:08:15 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	j = ft_strlen(s1);
	while (j && ft_strchr(set, s1[j]))
	{
		j--;
	}
	return (ft_substr(s1, i, j - i + 1));
}
