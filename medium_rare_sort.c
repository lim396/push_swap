#include "push_swap.h"

int	find_from_top(t_stack *stack, int chunk_min, int chunk_size)
{
	int		i;
	int		chunk_max;
	t_stack	*sentinel;

	sentinel = stack;
	i = 0;
	chunk_max = chunk_min + chunk_size - 1;
	while (stack->next != sentinel)
	{
		if (chunk_min <= stack->next->val && stack->next->val <= chunk_max)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_from_bottom(t_stack *stack, int chunk_min, int chunk_size)
{
	int		i;
	int		chunk_max;
	t_stack	*sentinel;

	sentinel = stack;
	i = 0;
	chunk_max = chunk_min + chunk_size - 1;
	while (stack->prev != sentinel)
	{		
		if (chunk_min <= stack->prev->val && stack->prev->val <= chunk_max)
			break ;
		i++;
		stack = stack->prev;
	}
	return (i + 1);
}

void	push_chunk(t_listack *stack, int size, int chunk_min, int one_chunk)
{
	int	ra_index;
	int	rra_index;
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = size - chunk_min;
	if (chunk_size > one_chunk)
		chunk_size = one_chunk;
	while (i < chunk_size)
	{
		ra_index = find_from_top(stack->a, chunk_min, chunk_size);
		rra_index = find_from_bottom(stack->a, chunk_min, chunk_size);
		if (ra_index <= rra_index)
			multiple_rotate_a(stack, ra_index, stack->order);
		else
			multiple_reverse_rotate_a(stack, rra_index, stack->order);
		pb(stack, stack->order);
		if (stack->b->next->val > chunk_min + (chunk_size / 2 - 1))
			rb(stack, stack->order);
		i++;
	}
}

void	push_from_bigger(t_listack *stack, int size)
{
	int	rb_index;
	int	rrb_index;
	int	sa_flag;
	int	rra_flag;
	int	i;

	sa_flag = 0;
	rra_flag = 0;
	rb_index = front_max_val_index(stack->b, size);
	rrb_index = back_max_val_index(stack->b, size);
	mult_rb_rrb(stack, rb_index, rrb_index, stack->order);
	pa(stack, stack->order);
	i = 0;
	while (i < size - 1)
	{
		rb_index = get_near_rb_index(stack->a, stack->b, sa_flag, rra_flag);
		rrb_index = get_near_rrb_index(stack->a, stack->b, sa_flag, rra_flag);
		mult_rb_rrb(stack, rb_index, rrb_index, stack->order);
		pa(stack, stack->order);
		receiv_proc(stack, &sa_flag, &rra_flag, stack->order);
		i++;
	}
}

void	medium_rare_sort(t_listack *stack, int size)
{
	int	chunk_min;
	int	one_chunk;

	chunk_min = 0;
	if (size >= 200)
		one_chunk = ONE_CHUNK_SIZE * 2;
	else
		one_chunk = ONE_CHUNK_SIZE;
	while (chunk_min < size)
	{
		push_chunk(stack, size, chunk_min, one_chunk);
		chunk_min += one_chunk;
	}
	push_from_bigger(stack, size);
}
