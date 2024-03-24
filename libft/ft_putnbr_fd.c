/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:31:11 by pevtimov          #+#    #+#             */
/*   Updated: 2023/12/11 20:38:02 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_local;

	if (n < 0)
	{
		n_local = (-1) * n;
		ft_putchar_fd('-', fd);
	}
	else
		n_local = n;
	if (n_local >= 10)
	{
		ft_putnbr_fd(n_local / 10, fd);
		ft_putnbr_fd(n_local % 10, fd);
	}
	if (n_local < 10)
		ft_putchar_fd(n_local + '0', fd);
}
