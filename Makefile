NAME = 

all: $(NAME) clean

$(NAME) : $(MY_OBJECTS)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
