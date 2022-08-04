CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
#HEADER = push_swap.h
LIBFT= ./libft/libft.a

SRCS=push_swap.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

#%.o: %.c
#	$(CC) $(CFLAGS) -o $@ $<

$(LIBFT):
	$(MAKE) -C ./libft


clean:
	$(MAKE) clean -C ./libft
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
