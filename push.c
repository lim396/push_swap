/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:22:13 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:22:15 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_stack_top(t_stack *stack, int val)
{
	t_stack	*node;

	node = new_node(val);
	if (node == NULL)
		return (-1);
	add_node_to_list(stack, node);
	return (0);
}

void	del_stack_top(t_stack *stack)
{
	t_stack	*top;
	t_stack	*top_next;

	top = stack->next;
	if (stack->prev == stack->next)
	{
		stack->prev = stack;
		stack->next = stack;
		free(top);
		return ;
	}
	top_next = top->next;
	stack->next = top_next;
	top_next->prev = stack;
	free(top);
}

int	push(t_stack *stack_1, t_stack *stack_2)
{
	int	flag;

	if (is_only_sentinel(stack_2))
		return (0);
	flag = add_stack_top(stack_1, stack_2->next->val);
	if (flag == -1)
		return (-1);
	del_stack_top(stack_2);
	return (0);
}

void	pa(t_listack *stack, t_olist *order)
{
	t_olist	*add_order;
	int		flag;

	if (is_only_sentinel(stack->b))
		return ;
	flag = push(stack->a, stack->b);
	if (flag == -1)
		error_handler(stack);
	order->kind = O_PA;
	add_order = new_order(order->kind);
	if (add_order == NULL)
		error_handler(stack);
	add_node_to_order_list(order, add_order);
}

void	pb(t_listack *stack, t_olist *order)
{
	t_olist	*add_order;
	int		flag;

	if (is_only_sentinel(stack->a))
		return ;
	flag = push(stack->b, stack->a);
	if (flag == -1)
		error_handler(stack);
	order->kind = O_PB;
	add_order = new_order(order->kind);
	if (add_order == NULL)
		error_handler(stack);
	add_node_to_order_list(order, add_order);
}
