
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // for PIDe
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <signal.h>

void handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("SIGUSR1\n");
		
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("SIGUSR2\n");
	}
	else
		ft_printf("signum: %d\n", signum);
}

int main(void)
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
	return(0);
}
 

//server
	// print PID
	// listen for SIG1 and SIG2
	// decode
	// print
	//Your server should be able to receive strings from several clients in a row without
	//needing to restart

//client

	// take PID and String from terminal

	// listen for SIG1 (signal received)
	// decode string to bits and send 0 - SIG1 1 - SIG2
