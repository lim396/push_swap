#include "push_swap.h"

int	front_max_val_index(t_stack *stack, int size)
{
	int	i;
	t_stack *sentinel;

	sentinel = stack;
	i = 0;
	while (stack->next != sentinel)
	{
		if (stack->next->val == size - 1)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

int	back_max_val_index(t_stack *stack, int size)
{
	int	i;
	t_stack *sentinel;

	sentinel = stack;
	i = 0;
	while (stack->prev != sentinel)
	{
		if (stack->prev->val == size - 1)
			break ;
		stack = stack->prev;
		i++;
	}
	return (i + 1);	
}
