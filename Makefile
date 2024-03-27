# Makefile for server and client executables

# Compiler and flags
CC := gcc
CFLAGS = -Wall -Wextra -Werror -g   -fsanitize=address

# Directories
CLIENT_DIR := client_src
SERVER_DIR := server_src
LIBFT_DIR := libft
FT_PRINTF_DIR := ft_printf

# Source files
CLIENT_SRC := $(wildcard $(CLIENT_DIR)/*.c)
SERVER_SRC := $(wildcard $(SERVER_DIR)/*.c)
LIBFT_SRC := $(wildcard $(LIBFT_DIR)/*.c)
FT_PRINTF_SRC := $(wildcard $(FT_PRINTF_DIR)/*.c)

# Object files
CLIENT_OBJ := $(CLIENT_SRC:.c=.o)
SERVER_OBJ := $(SERVER_SRC:.c=.o)
LIBFT_OBJ := $(LIBFT_SRC:.c=.o)
FT_PRINTF_OBJ := $(FT_PRINTF_SRC:.c=.o)

# Executables
CLIENT := client
SERVER := server

# Targets
all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(SERVER_OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re

