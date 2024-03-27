/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:38:19 by pevtimov          #+#    #+#             */
/*   Updated: 2024/02/19 18:01:59 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_type(char var_type, va_list args)
{
	int	c;

	c = 0;
	if (var_type == 'c')
		c = ft_putchar_and_count(va_arg(args, int));
	else if (var_type == 's')
		c = ft_putstr_and_count(va_arg(args, char *));
	else if (var_type == 'p')
		c = ft_putstring_ptr((unsigned long long) va_arg(args, void *), HEX_L);
	else if (var_type == 'd')
		c = ft_putstring_int((unsigned int) va_arg(args, unsigned int), DEC);
	else if (var_type == 'i')
		c = ft_putstring_int((unsigned int) va_arg(args, unsigned int), DEC);
	else if (var_type == 'u')
		c = ft_putstring_base((unsigned int) va_arg(args, unsigned int), DEC);
	else if (var_type == 'x')
		c = ft_putstring_base((unsigned int) va_arg(args, unsigned int), HEX_L);
	else if (var_type == 'X')
		c = ft_putstring_base((unsigned int) va_arg(args, unsigned int), HEX_U);
	else if (var_type == '%')
		c = ft_putchar_and_count('%');
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (str != NULL)
		va_start(args, str);
	else
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar_and_count(str[i]);
		else
			count += ft_find_type(str[++i], args);
		i++;
	}
	va_end(args);
	return (count);
}
