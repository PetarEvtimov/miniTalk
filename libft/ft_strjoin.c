/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:49:52 by pevtimov          #+#    #+#             */
/*   Updated: 2023/11/28 23:27:40 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
