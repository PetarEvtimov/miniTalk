/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:58:43 by pevtimov          #+#    #+#             */
/*   Updated: 2024/04/05 15:04:23 by pevtimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <signal.h>

void	encode_and_send(pid_t pid_srv, char *str)
{
	int		i;
	char	c;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 7;
		c = str[i];
		while (j >= 0)
		{
			if ((c >> j) & 1)
				kill(pid_srv, SIGUSR1);
			else
				kill(pid_srv, SIGUSR2);
			usleep(400);
			j--;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid_srv;
	char	*str;

	if (argc == 3)
	{
		pid_srv = ft_atoi(argv[1]);
		str = argv[2];
		encode_and_send(pid_srv, str);
	}
	else
		ft_printf("Enter correct input!");
	return (0);
}
