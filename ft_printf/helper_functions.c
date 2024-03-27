/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:30:06 by pevtimov          #+#    #+#             */
/*   Updated: 2024/03/27 19:35:26 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_strlen_pf(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_get_lenght(unsigned long long num, unsigned int size_base)
{
	unsigned int	size;

	size = 1;
	while (num >= size_base)
	{
		size++;
		num /= size_base;
	}
	return (size);
}

void	ft_bzero_printf(void *s, int n)
{
	char	*ch_s;

	ch_s = (char *)s;
	while (n > 0)
	{
		*ch_s = '\0';
		ch_s++;
		n--;
	}
}

void	*ft_calloc_printf(int nmemb, size_t size)
{
	void	*ptr;
	size_t	num_bytes;

	num_bytes = nmemb * size;
	ptr = malloc(num_bytes);
	if (ptr == NULL)
		return (NULL);
	ft_bzero_printf(ptr, num_bytes);
	return (ptr);
}
