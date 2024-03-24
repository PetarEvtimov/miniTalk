/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:17:00 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/11 18:36:09 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	char		*ptr_dest_start;
	const char	*ptr_src;

	if (dest == NULL & src == NULL)
		return (NULL);
	ptr_dest = (char *) dest;
	ptr_dest_start = ptr_dest;
	ptr_src = (char *) src;
	while (n > 0)
	{
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
		n--;
	}
	return (ptr_dest_start);
}
