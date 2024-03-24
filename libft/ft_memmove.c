/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:46:16 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/11 18:47:28 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*ch_dest;
	const char		*ch_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	ch_src = (char *)src;
	ch_dest = (char *)dest;
	if (ch_src < ch_dest)
	{
		while (n-- > 0)
			ch_dest[n] = ch_src[n];
	}
	else
	{
		while (n-- > 0)
			*ch_dest++ = *ch_src++;
	}
	return (dest);
}
