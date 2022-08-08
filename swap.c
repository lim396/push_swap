#include "push_swap.h"

t_stack	*find_prev_changed_pos(t_stack *stack, int prev_index)
{
	t_stack	*prev_changed;

	if (prev_index == SENTINEL)
		prev_changed = stack;
	if (prev_index == TOP)
		prev_changed = stack->next;
	if (prev_index == BOTTOM)
		prev_changed = stack->prev;
	return (prev_changed);
}

t_stack	*find_next_changed_pos(t_stack *stack, int prev_index)
{
	t_stack	*next_changed;

	if (prev_index == SENTINEL)
		next_changed = stack->next;
	if (prev_index == TOP)
		next_changed = stack->next->next;
	if (prev_index == BOTTOM)
		next_changed = stack;
	return (next_changed);
}

void	swap(t_stack *stack, int prev_index)
{
	t_stack	*prev_changed;
	t_stack	*next_changed;
	t_stack	*next_tmp;
	t_stack	*prev_tmp;

	prev_changed = find_prev_changed_pos(stack, prev_index);
	next_changed = find_next_changed_pos(stack, prev_index);
	next_tmp = next_changed->next;
	prev_changed->next = next_changed->next;
	next_changed->next = prev_changed;
	prev_changed->prev->next = next_changed;
	prev_tmp = prev_changed->prev;
	prev_changed->prev = next_changed;
	next_changed->prev = prev_tmp;
	next_tmp->prev = prev_changed;
}

void	sa(t_listack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->a->next == stack->a->prev || is_only_sentinel(stack->a))
		return ;
	swap(stack->a, TOP);
	order->kind = O_SA;
	add_order = new_order(order->kind);
	if (add_order == NULL)
		error_handler(stack);
	add_node_to_order_list(order, add_order);
}

void	sb(t_listack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->b->next == stack->b->prev || is_only_sentinel(stack->b))
		return ;
	swap(stack->b, TOP);
	order->kind = O_SB;
	add_order = new_order(order->kind);
	if (add_order == NULL)
		error_handler(stack);
	add_node_to_order_list(order, add_order);
}
