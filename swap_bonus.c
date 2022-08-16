/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:22:57 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:22:59 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	sa(t_stack *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
		return ;
	swap(stack, TOP);
}

void	sb(t_stack *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
		return ;
	swap(stack, TOP);
}
