NAME = push_swap

SRC_DIR = src
INC_DIR = include
LIB_DIR = ft_printf

SRC = ft_push_swap.c \
	ft_push_swap_utils1.c \
	ft_push_swap_utils2.c \

OBJ = $(SRC:%.c=$(SRC_DIR)/%.o)

LIBFT = $(LIB_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)



clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
