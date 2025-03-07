CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar
ARFLAGS = rcs
RM      = rm -f

SRCs    = ft_hex.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_print_addr.c ft_putnbr_unsigned.c
OBJs    = $(SRCs:.c=.o)
NAME    = libftprintf.a

all: $(NAME)

$(NAME): $(OBJs)
	$(AR) $(ARFLAGS) $(NAME) $(OBJs)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJs)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
