/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:22:37 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:22:39 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_listack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->a->next == stack->a->prev || is_only_sentinel(stack->a))
		return ;
	swap(stack->a, SENTINEL);
	order->kind = O_RA;
	add_order = new_order(order->kind);
	if (add_order == NULL)
		error_handler(stack);
	add_node_to_order_list(order, add_order);
}

void	rb(t_listack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->b->next == stack->b->prev || is_only_sentinel(stack->b))
		return ;
	swap(stack->b, SENTINEL);
	order->kind = O_RB;
	add_order = new_order(order->kind);
	if (add_order == NULL)
		error_handler(stack);
	add_node_to_order_list(order, add_order);
}

void	rra(t_listack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->a->next == stack->a->prev || is_only_sentinel(stack->a))
		return ;
	swap(stack->a, BOTTOM);
	order->kind = O_RRA;
	add_order = new_order(order->kind);
	if (add_order == NULL)
		error_handler(stack);
	add_node_to_order_list(order, add_order);
}

void	rrb(t_listack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->b->next == stack->b->prev || is_only_sentinel(stack->b))
		return ;
	swap(stack->b, BOTTOM);
	order->kind = O_RRB;
	add_order = new_order(order->kind);
	if (add_order == NULL)
		error_handler(stack);
	add_node_to_order_list(order, add_order);
}
