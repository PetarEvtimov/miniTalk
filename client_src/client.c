#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // for PIDe
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <signal.h>

void string_to_bits(pid_t pid_srv, char* text)
{
	char one = 1;
	

}

int main(int argc, char *argv[])
{
	pid_t	pid_srv;
	char	*text;

	if(argc == 3)
	{
		pid_srv = ft_atoi(argv[1]);
		text = argv[2];
	}
	ft_printf("text: %s\n", text);
	int i = 0;

	while(*text)
	{
		ft_printf("i: %d\n", ++i);
		if(*text == '0')
			kill(pid_srv, SIGUSR1);
		else
			kill(pid_srv, SIGUSR2);
		text++;
		usleep(300);
	}
	return(0);
}