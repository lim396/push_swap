#include "checker_bonus.h"

void	ra(t_stack *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
		return ;
	swap(stack, SENTINEL);
}

void	rb(t_stack *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
		return ;
	swap(stack, SENTINEL);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
