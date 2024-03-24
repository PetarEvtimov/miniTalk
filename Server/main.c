#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "../libft/ft_putnbr_fd.c"
#include "../libft/ft_putchar_fd.c"

int server_pid;

void sigusr1_handler(int signum) {
    // Upon receiving SIGUSR1, send the server's PID to the client
    printf("Signal received\n");
    printf("Sending server PID to client: %d\n", server_pid);
    if (kill(server_pid, SIGUSR1) == 0) {
        printf("Server PID sent successfully.\n");
    } else {
        perror("kill");
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    // Get server PID
    server_pid = getpid();

    // Register signal handler for SIGUSR1

    signal(SIGUSR1, sigusr1_handler);


    int fd = open("../serverPid.txt", O_RDWR);
    ft_putnbr_fd(server_pid, fd);
    close(fd);


    // Print server PID
    printf("Server PID: %d\n", server_pid);

    // Server is now waiting for the client to initiate communication
    printf("Server: Waiting for signal from client...\n");
    while (1) {
        sleep(1); // Just to keep the server alive
    }

    return 0;
}
