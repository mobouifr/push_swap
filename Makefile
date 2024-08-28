NAME = push_swap
SRC = push_swap.c \
	  parse.c \
      ./libft/ft_atoi.c \
	  ./libft/ft_split.c \
	  ./libft/ft_isdigit.c \
	  ./linked_list_functions/ft_lstnew.c \
	  ./linked_list_functions/ft_lstaddback.c \
	  ./linked_list_functions/ft_lstaddfront.c \
	  ./linked_list_functions/ft_lstsize.c \
	  ./linked_list_functions/ft_lstmax.c \
	  ./linked_list_functions/ft_lstmin.c \
	  ./linked_list_functions/ft_lstdisplay.c \
	  ./linked_list_functions/ft_lstclear.c \
	  ./operations/push_operations.c \
	  ./operations/reverse_rotate_operations.c \
	  ./operations/rotate_operations.c \
	  ./operations/swap_operations.c \
	  ./push_swap_functions/find_price.c \
	  ./push_swap_functions/update_index.c \
	  ./push_swap_functions/fill_stack_a.c \
	  ./push_swap_functions/check_lowestnum.c \
	  ./push_swap_functions/find_price_extn.c \
	  ./push_swap_functions/find_target.c \
	  ./push_swap_functions/node_positioning_a.c \
	  ./push_swap_functions/node_positioning_b.c \
	  ./push_swap_functions/sorting_functions.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
