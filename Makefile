NAME = push_swap
BONUS_NAME = checker
SRC_DIR = src
INC_DIR = include
LIB_DIR = ft_printf
BONUS_DIR = bonus

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
	utils/validation.c \
	turk/turk_utils.c \
	turk/cost.c \
	turk/exec.c \
	turk/exec_2.c

SRC_BONUS = get_next_line/get_next_line_bonus.c \
			get_next_line/get_next_line_utils_bonus.c \
			moves/push_bonus.c \
			moves/reverse_rotate_bonus.c \
			moves/rotate_bonus.c \
			moves/swap_bonus.c \
			push_swap/exec_bonus.c \
			push_swap/push_swap_bonus.c \
			stack/stack_2.c \
			stack/stack.c \
			utils/ft_split_bonus.c \
			utils/utils_bonus.c \
			utils/validation_bonus.c

OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(BONUS_DIR)/, $(SRC_BONUS:.c=.o))

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

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)


.PHONY: all clean fclean re
