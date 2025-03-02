CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft -Lft_printf -lftprintf

SRC = server.c client.c server_bonus.c client_bonus.c
OBJ = $(SRC:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

all: libft printf $(NAME_SERVER) $(NAME_CLIENT)

bonus: libft printf $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

libft:
	make -C libft

printf:
	make -C ft_printf

$(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS): %: %.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

.PHONY: all bonus libft printf clean fclean re
