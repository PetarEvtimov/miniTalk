
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // for PIDe
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <signal.h>
#include <signal.h>

void handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("0");
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("1");
	}
	else
		ft_printf("signum: %d\n", signum);
}

int main(void)
{
	pid_t	pid_srv;
	pid_srv = getpid();

	ft_printf("Server PID: %d\n", pid_srv);


	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
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

	// Should we block
//client

	// take PID and String from terminal

	// listen for SIG1 (signal received)
	// decode string to bits and send 0 - SIG1 1 - SIG2
