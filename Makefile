NAME = push_swap

SRC_DIR = src
INC_DIR = include
LIB_DIR = ft_printf

SRC = push_swap/push_swap.c \
	stack/stack.c \
	moves/swap.c \
	moves/push.c \
	moves/rotate.c \
	moves/reverse_rotate.c \
	push_swap/sort.c \
	utils/ft_split.c \
	utils/ft_substr.c \
	utils/utils.c \
	turk/turk_utils.c \
	turk/cost.c \
	turk/exec.c \
	turk/exec_2.c

OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

LIBFT = $(LIB_DIR)/libftprintf.a

CC = @cc
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
