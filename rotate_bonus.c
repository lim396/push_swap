/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:22:31 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:22:33 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_stack *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
		return ;
	swap(stack, SENTINEL);
}

void	rb(t_stack *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
		return ;
	swap(stack, SENTINEL);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
