/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:12:21 by pevtimov          #+#    #+#             */
/*   Updated: 2024/02/19 18:02:03 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_and_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_and_count(char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (*s)
	{
		count += ft_putchar_and_count(*s);
		s++;
	}
	return (count);
}

int	ft_putstring_ptr(unsigned long long ptr_address, char *base)
{
	int		count;
	char	*str;

	count = 0;
	if (!ptr_address)
		count += ft_putstr_and_count("(nil)");
	else
	{
		count += ft_putstr_and_count("0x");
		str = ft_convert_num_to_base(ptr_address, base);
		count += ft_putstr_and_count(str);
		free(str);
	}
	return (count);
}

int	ft_putstring_base(unsigned int num, char *base)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_convert_num_to_base(num, base);
	count += ft_putstr_and_count(str);
	free(str);
	return (count);
}

int	ft_putstring_int(int num, char *base)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar_and_count('-');
		if (num == -2147483648)
		{
			count += ft_putstr_and_count("2147483648");
			return (count);
		}
		else
			num = num * (-1);
	}
	count += ft_putstring_base(num, base);
	return (count);
}
