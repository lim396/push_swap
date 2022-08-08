#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_handler(t_listack *stack)
{
	ft_putstr_fd("Error\n", 2);
	stack_free(stack->a);
	stack_free(stack->b);
	order_list_free(stack->order);
	exit(1);
}
