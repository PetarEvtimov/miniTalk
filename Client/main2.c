#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../libft/libft.h"
#include "../libft/get_next_line/get_next_line.h"
#include "../libft/ft_putnbr_fd.c"
#include "../libft/ft_putchar_fd.c"
#include "../libft/get_next_line/get_next_line.h"
#include "../libft/get_next_line/get_next_line.c"
#include "../libft/get_next_line/get_next_line_utils.c"
#include "../libft/ft_atoi.c"
#include "../libft/ft_isdigit.c"

#include <fcntl.h>

int server_pid; // Replace with the actual server PID

void sigusr1_handler(int signum) {
	printf("Received server SIGNUM from server: %d\n", signum);
	// Client can now use the server PID for further communication, if needed
	exit(EXIT_SUCCESS);
}

int main(void) {


	// Register signal handler for SIGUSR1
	//signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR1, sigusr1_handler);
	// Read PID of the server off of a
	int fd = open("../serverPid.txt", O_RDONLY);

	if (fd > 0)
	{
		server_pid = ft_atoi(get_next_line(fd));
	}
	else
	{
		printf("Error reading the file!! fd: %d\n", fd);
	}
	close(fd);

	printf("Server PID: %d\n", server_pid);


	if (kill(server_pid, SIGUSR1) == 0) {
        printf("Signal sent successfully.\n");
    } else {
        perror("Error sending signal");
        exit(EXIT_FAILURE);
    }
	// Send a SIGUSR1 signal to the server to request its PID
	//if (kill(server_pid, SIGUSR1) == 0) {
	//	printf("SIGUSR1 signal sent to server successfully.\n");
	//} else {
	//	perror("kill");
	//	return EXIT_FAILURE;
	//}

	// Client now waits for the server to respond with its PID

	//printf("Waiting for server PID...\n");
	while (1) {
		sleep(1); // Just to keep the client alive
	}

	return 0;
}
