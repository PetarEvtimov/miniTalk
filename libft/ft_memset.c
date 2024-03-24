/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:23:11 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/06 15:35:19 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ch_s;
	char	*ch_s_start;

	ch_s = (char *)s;
	ch_s_start = ch_s;
	while (n > 0)
	{
		*ch_s = c;
		ch_s++;
		n--;
	}
	return (ch_s_start);
}
