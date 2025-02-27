CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client

LIBFT_DIR = libft
PRINTF_DIR = ft_printf
LIBS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: libft printf $(NAME_SERVER) $(NAME_CLIENT)

libft:
	make -C $(LIBFT_DIR)

printf:
	make -C $(PRINTF_DIR)

$(NAME_SERVER) $(NAME_CLIENT): %: %.o
	$(CC) $(CFLAGS) $< $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all libft printf clean fclean re