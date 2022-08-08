#include "push_swap.h"

int	top_near(t_stack *stack, int find_val1, int find_val2, int find_val3)
{
	t_stack	*sentinel;
	int i;

	sentinel = stack;
	i = 0;
	while (stack->next != sentinel)
	{
		if (stack->next->val == find_val1
			|| stack->next->val == find_val2
			|| stack->next->val == find_val3)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

int	bottom_near(t_stack *stack, int find_val1, int find_val2, int find_val3)
{
	t_stack	*sentinel;
	int	i;

	sentinel = stack;
	i = 0;
	while (stack->prev != sentinel)
	{
		if (stack->prev->val == find_val1
			|| stack->prev->val == find_val2
			|| stack->prev->val == find_val3)
			break ;
		i++;
		stack = stack->prev;
	}
	return (i + 1);
}

int get_near_rb_index(t_stack *a, t_stack *b, int sa_flag, int rra_flag)
{
    int a_top_val;
    int rb_index;

    a_top_val = a->next->val;
    if (rra_flag == 1 && sa_flag == 0)
        rb_index = top_near(b, a_top_val - 1, a_top_val - 2, -3);
    else if (sa_flag == 1 && rra_flag == 0)
        rb_index = top_near(b, a_top_val + 1, a_top_val - 1, -3);
    else if (sa_flag == 1 && rra_flag == 1)
        rb_index = top_near(b, a_top_val + 1, -3, -3);
    else
		rb_index = top_near(b, a_top_val - 1, a_top_val - 2, a_top_val - 3);
    return (rb_index);
}


int get_near_rrb_index(t_stack *a, t_stack *b, int sa_flag, int rra_flag)
{
    int a_top_val;
    int rrb_index;

    a_top_val = a->next->val;
    if (rra_flag == 1 && sa_flag == 0)
        rrb_index = bottom_near(b, a_top_val - 1, a_top_val - 2, -3);
    else if (sa_flag == 1 && rra_flag == 0)
        rrb_index = bottom_near(b, a_top_val + 1, a_top_val - 1, -3);
    else if (sa_flag == 1 && rra_flag == 1)
        rrb_index = bottom_near(b, a_top_val + 1, -3, -3);
    else
        rrb_index = bottom_near(b, a_top_val - 1, a_top_val - 2, a_top_val - 3);
    return (rrb_index);
}
