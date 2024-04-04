#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // for PIDe
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <signal.h>

int main(int argc, char *argv[])
{	
	pid_t	pid_srv;
	char	*text;

	if(argc == 3)
	{
		pid_srv = ft_atoi(argv[1]);
		text = argv[2];
	}

	ft_printf("%d / %s", pid_srv, text);

	ft_printf("USR1: %d",kill(pid_srv, SIGUSR1));
	pause();
	ft_printf("USR2: %d",kill(pid_srv, SIGUSR2));

	return(0);
}