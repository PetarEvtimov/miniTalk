/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:57:21 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/03 17:36:00 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ch_s1;
	const char	*ch_s2;

	ch_s1 = s1;
	ch_s2 = s2;
	while (n > 0)
	{
		if ((unsigned char)*ch_s1 != (unsigned char)*ch_s2)
			return ((unsigned char)*ch_s1 - (unsigned char)*ch_s2);
		ch_s1++;
		ch_s2++;
		n--;
	}
	return (0);
}
