CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
CHECKER = _checker
#HEADER = push_swap.h
LIBFT= ./libft/libft.a

M_SRCS=push_swap.c
B_SRCS=checker.c get_next_line.c get_next_line_utils.c

M_OBJS=$(M_SRCS:.c=.o)
B_OBJS=$(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(M_OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C ./libft

bonus: $(CHECKER)

$(CHECKER): $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(B_OBJS) $(LIBFT)


clean:
	$(MAKE) clean -C ./libft
	$(RM) *.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
