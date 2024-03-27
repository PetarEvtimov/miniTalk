/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:29:01 by pevtimov          #+#    #+#             */
/*   Updated: 2024/03/27 19:36:16 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_num_to_base(unsigned long long num, char *base)
{
	unsigned int		size_base;
	unsigned int		size_str;
	char				*num_str;

	size_base = ft_strlen_pf(base);
	size_str = ft_get_lenght(num, size_base);
	num_str = ft_calloc_printf((size_str + 1), sizeof(char));
	if (num_str == NULL)
		return (NULL);
	while (size_str)
	{
		size_str--;
		num_str[size_str] = base[num % size_base];
		num /= size_base;
	}
	return (num_str);
}
