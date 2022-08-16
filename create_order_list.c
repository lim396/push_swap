/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_order_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:19:40 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:19:42 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_olist	*new_order_sentinel(void)
{
	t_olist	*order;

	order = (t_olist *)malloc(sizeof(t_olist));
	if (order == NULL)
		return (NULL);
	order->prev = order;
	order->next = order;
	order->kind = O_NO;
	return (order);
}

t_olist	*new_order(t_okind kind)
{
	t_olist	*order;

	order = (t_olist *)malloc(sizeof(t_olist));
	if (order == NULL)
		return (NULL);
	order->next = NULL;
	order->prev = NULL;
	order->kind = kind;
	return (order);
}

bool	is_only_sentinel_order(t_olist *stack)
{
	return (stack->next == stack && stack->prev == stack);
}

void	add_node_to_order_list(t_olist *sentinel, t_olist *node)
{
	t_olist	*head_next;

	if (is_only_sentinel_order(sentinel))
	{
		sentinel->prev = node;
		sentinel->next = node;
		node->prev = sentinel;
		node->next = sentinel;
		return ;
	}
	head_next = sentinel->next;
	sentinel->next = node;
	head_next->prev = node;
	node->prev = sentinel;
	node->next = head_next;
}
