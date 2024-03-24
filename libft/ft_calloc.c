/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:29:16 by pevtimov          #+#    #+#             */
/*   Updated: 2023/11/26 17:16:05 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	num_bytes;

	num_bytes = nmemb * size;
	ptr = malloc(num_bytes);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, num_bytes);
	return (ptr);
}
