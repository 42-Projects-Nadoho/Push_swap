NAME = push_swap

SRC_DIR = src
INC_DIR = include
LIB_DIR = ft_printf

SRC = push_swap.c \
	stack.c \
	utils.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c

OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

LIBFT = $(LIB_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INC_DIR) -I$(LIB_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
