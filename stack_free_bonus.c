#include "push_swap.h"

void	*all_free(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

void	stack_free(t_stack *stack)
{
	t_stack	*sentinel;
	t_stack	*stack_next;

	sentinel = stack;
	while (stack->next != sentinel)
	{
		stack_next = stack->next;
		stack->next = stack_next->next;
		free(stack_next);
		stack_next = NULL;
	}
	free(sentinel);
	sentinel = NULL;
}
