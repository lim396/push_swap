#include "push_swap.h"

void	less_than_three_sort(t_listack *stack, t_olist *order, int size)
{
	int	top;
	int	medium;
	int	bottom;

	top = stack->a->next->val;
	medium = stack->a->next->next->val;
	bottom = stack->a->prev->val;
	if ((top > medium && top < bottom && medium < bottom) || size == 2)
		sa(stack, order);
	if (top > medium && top > bottom && medium > bottom)
	{
		sa(stack, order);
		rra(stack, order);
	}
	if (top > medium && top > bottom && medium < bottom)
		ra(stack, order);
	if (top < medium && top < bottom && medium > bottom)
	{
		sa(stack, order);
		ra(stack, order);
	}
	if (top < medium && top > bottom && medium > bottom)
		rra(stack, order);
}

int	find_min(t_stack *stack, int size)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min_index = 0;
	min = stack->next->val;
	while (i < size)
	{
		if (stack->next->val < min)
		{
			min = stack->next->val;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

int	pb_min_val(t_listack *stack, int *size, t_olist *order)
{
	int	min_index;
	int	n_of_pb;

	n_of_pb = 0;
	min_index = find_min(stack->a, *size);
	if (min_index < ((*size + 1) / 2))
	{
		while (min_index)
		{
			ra(stack, order);
			min_index--;
		}
	}
	else
	{
		while (*size - min_index)
		{
			rra(stack, order);
			min_index++;
		}
	}
	pb(stack, order);
	n_of_pb++;
	(*size)--;
	return (n_of_pb);
}

void	less_than_five_sort(t_listack *stack, int size)
{
	int	n_of_pb;

	n_of_pb = 0;
	while (size > 3)
	{
		n_of_pb += pb_min_val(stack, &size, stack->order);
	}
	less_than_three_sort(stack, stack->order, 3);
	while (n_of_pb-- > 0)
		pa(stack, stack->order);
}
