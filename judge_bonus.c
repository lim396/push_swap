#include "checker_bonus.h"

bool	is_sorted(t_stack *stack)
{
	t_stack	*sentinel;

	sentinel = stack;
	while (stack->next->next != sentinel)
	{
		if (stack->next->val > stack->next->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	measure_stack(t_stack *stack)
{
	int		i;
	t_stack	*sentinel;

	sentinel = stack;
	i = 0;
	while (stack->next != sentinel)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	judge_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) || measure_stack(stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
