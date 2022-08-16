/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:21:38 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:21:39 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multiple_rotate_a(t_listack *stack, int r_index, t_olist *order)
{
	while (r_index--)
		ra(stack, order);
}

void	multiple_reverse_rotate_a(t_listack *st, int rr_index, t_olist *order)
{
	while (rr_index--)
		rra(st, order);
}

void	multiple_rotate_b(t_listack *stack, int r_index, t_olist *order)
{
	while (r_index--)
		rb(stack, order);
}

void	multiple_reverse_rotate_b(t_listack *st, int rr_index, t_olist *order)
{
	while (rr_index--)
		rrb(st, order);
}

void	mult_rb_rrb(t_listack *b, int rb_index, int rrb_index, t_olist *order)
{
	if (rb_index <= rrb_index)
		multiple_rotate_b(b, rb_index, order);
	else
		multiple_reverse_rotate_b(b, rrb_index, order);
}
