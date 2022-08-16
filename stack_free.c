/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:22:49 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:22:51 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*all_free(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

void	stack_free(t_stack *stack)
{
	t_stack	*sentinel;
	t_stack	*stack_next;

	sentinel = stack;
	while (stack->next != sentinel)
	{
		stack_next = stack->next;
		stack->next = stack_next->next;
		free(stack_next);
		stack_next = NULL;
	}
	free(sentinel);
	sentinel = NULL;
}

void	order_list_free(t_olist *order)
{
	t_olist	*sentinel;
	t_olist	*order_next;

	sentinel = order;
	while (order->next != sentinel)
	{
		order_next = order->next;
		order->next = order_next->next;
		free(order_next);
		order_next = NULL;
	}
	free(sentinel);
	sentinel = NULL;
}
