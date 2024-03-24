
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "../libft/ft_putnbr_fd.c"
#include "../libft/ft_putchar_fd.c"
#include "../libft/get_next_line/get_next_line.h"
#include "../libft/get_next_line/get_next_line.c"
#include "../libft/get_next_line/get_next_line_utils.c"

int main(void)
{
	 int server_pid = 999;


    int fd = open("serverPid.txt", O_RDWR);
	printf("fd: %d\n",fd);
    ft_putnbr_fd(server_pid, fd);
	close(fd);
	fd = open("serverPid.txt", O_RDWR);
	printf("PID: %s\n", get_next_line(fd));
	close(fd);
	
	return (0);
}