/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:32 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/03 17:39:17 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ch_s;

	ch_s = s;
	while (n > 0)
	{
		if ((unsigned char)*ch_s == (unsigned char)c)
			return ((void *)ch_s);
		ch_s++;
		n--;
	}
	return (NULL);
}
