NAME = libftprintf.a

SRC = ft_printf.c ft_putadress.c ft_putchar_fd.c ft_puthexa.c ft_putnbr_fd.c ft_putstr_fd.c ft_strjoin.c ft_strlen.c

OBJ = $(SRC:.c=.o)

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re