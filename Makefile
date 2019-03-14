
NAME		= fillit
CFLAGS	= -Wall -Werror  -Wextra -g -I. -c
FILES	= *.c
OBJ		= $(FILES:%.c=%.o)
LIB 	= libft/libft.a	
all: $(NAME)
	
$(NAME): $(OBJ)
	make -C ./libft
	@gcc $(OBJ) $(LIB) -g  -o $(NAME)

$(OBJ): $(FILES)
	@gcc $(CFLAGS)  $(FILES) 
clean:
	@rm -f $(OBJ)
	@make fclean -C ./libft
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
