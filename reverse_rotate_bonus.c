/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:22:26 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:22:28 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_stack *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
		return ;
	swap(stack, BOTTOM);
}

void	rrb(t_stack *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
		return ;
	swap(stack, BOTTOM);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
