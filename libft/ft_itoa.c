/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:22:56 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/06 18:11:27 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlenght(int n)
{
	int	str_lenght;

	str_lenght = 0;
	if (n <= 0)
		str_lenght = 1;
	while (n != 0)
	{
		n = n / 10;
		str_lenght++;
	}
	return (str_lenght);
}

char	*ft_itoa(int n)
{
	long	n_local;
	int		str_lenght;
	char	*result;

	n_local = n;
	if (n < 0)
		n_local = n_local * (-1);
	str_lenght = ft_getlenght(n);
	result = malloc(str_lenght + 1);
	if (result == NULL)
		return (NULL);
	result[str_lenght--] = '\0';
	if (n_local == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n_local > 0)
	{
		result[str_lenght--] = n_local % 10 + '0';
		n_local = n_local / 10;
	}
	return (result);
}
