CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
CHECKER = _checker
M_HEADER = push_swap.h
B_HEADER = checker_bonus.h
LIBFT= ./libft/libft.a

M_SRCS= push_swap.c \
		coordinate_compression.c \
		create_arry.c \
		create_order_list.c \
		create_stack_list.c \
		error_check.c \
		error_handler.c \
		find_max_val_index.c \
		find_near_index.c \
		less_than_five_sort.c \
		medium_rare_sort.c \
		multiple_rotate.c \
		print_order.c \
		push.c \
		rececive_process.c \
		rotate.c \
		stack_free.c \
		swap.c 

B_SRCS= checker_bonus.c \
		get_next_line.c \
		get_next_line_utils.c \
		coordinate_compression_bonus.c \
		create_arry_bonus.c \
		create_stack_list_bonus.c \
		error_check_bonus.c \
		error_handler_bonus.c \
		judge_bonus.c \
		push_bonus.c \
		reverse_rotate_bonus.c \
		rotate_bonus.c \
		stack_free_bonus.c \
		swap_bonus.c

M_OBJS=$(M_SRCS:.c=.o)
B_OBJS=$(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJS) $(M_HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(M_OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C ./libft

bonus: $(CHECKER)

$(CHECKER): $(B_OBJS) $(B_HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(B_OBJS) $(LIBFT)


clean:
	$(MAKE) clean -C ./libft
	$(RM) *.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
