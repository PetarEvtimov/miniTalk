/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:57:56 by pevtimov          #+#    #+#             */
/*   Updated: 2024/04/05 15:59:45 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <signal.h>
#include <time.h>

void	handler(int signum)
{
	static int	index;
	static char	c;

	c <<= 1;
	if (signum == SIGUSR1)
		c |= 1;
	if (index == 7)
	{
		write(1, &c, 1);
		c = 0;
		index = 0;
	}
	else
		index++;
}

int	main(void)
{
	pid_t	pid_srv;

	pid_srv = getpid();
	ft_printf("Server PID: %d\n", pid_srv);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
	return (0);
}
