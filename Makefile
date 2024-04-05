# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevtimov <pevtimov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 12:57:19 by pevtimov          #+#    #+#              #
#    Updated: 2024/04/05 13:04:01 by pevtimov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS = -Wall -Wextra -Werror -g   -fsanitize=address

CLIENT_DIR := client_src
SERVER_DIR := server_src
LIBFT_DIR := libft
FT_PRINTF_DIR := ft_printf

CLIENT_SRC := $(wildcard $(CLIENT_DIR)/*.c)
SERVER_SRC := $(wildcard $(SERVER_DIR)/*.c)
LIBFT_SRC := $(wildcard $(LIBFT_DIR)/*.c)
FT_PRINTF_SRC := $(wildcard $(FT_PRINTF_DIR)/*.c)

CLIENT_OBJ := $(CLIENT_SRC:.c=.o)
SERVER_OBJ := $(SERVER_SRC:.c=.o)
LIBFT_OBJ := $(LIBFT_SRC:.c=.o)
FT_PRINTF_OBJ := $(FT_PRINTF_SRC:.c=.o)

CLIENT := client
SERVER := server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(SERVER_OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
