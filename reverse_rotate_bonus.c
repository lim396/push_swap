#include "checker_bonus.h"

void    rra(t_stack *stack)
{
    if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
    swap(stack, BOTTOM);
}

void    rrb(t_stack *stack)
{
    if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
    swap(stack, BOTTOM);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
