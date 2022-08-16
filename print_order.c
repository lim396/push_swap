/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:21:44 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:21:46 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_print_rr(t_olist *order)
{
	int	flag;

	flag = 0;
	if (order->prev->kind == O_RA)
	{
		if (order->prev->prev->kind == O_RB)
		{
			ft_putstr_fd("rr\n", 1);
			flag = 1;
		}
		else
			ft_putstr_fd("ra\n", 1);
	}
	if (order->prev->kind == O_RB)
	{
		if (order->prev->prev->kind == O_RA)
		{
			ft_putstr_fd("rr\n", 1);
			flag = 1;
		}
		else
			ft_putstr_fd("rb\n", 1);
	}
	return (flag);
}

int	check_print_rrr(t_olist *order)
{
	int	flag;

	flag = 0;
	if (order->prev->kind == O_RRA)
	{
		if (order->prev->prev->kind == O_RRB)
		{
			ft_putstr_fd("rrr\n", 1);
			flag = 1;
		}
		else
			ft_putstr_fd("rra\n", 1);
	}
	if (order->prev->kind == O_RRB)
	{
		if (order->prev->prev->kind == O_RRA)
		{
			ft_putstr_fd("rrr\n", 1);
			flag = 1;
		}
		else
			ft_putstr_fd("rrb\n", 1);
	}
	return (flag);
}

void	print_order(t_olist *order)
{
	t_olist	*sentinel;
	int		rr_flag;
	int		rrr_flag;

	sentinel = order;
	while (order->prev != sentinel)
	{
		if (order->prev->kind == O_SA)
			ft_putstr_fd("sa\n", 1);
		if (order->prev->kind == O_SB)
			ft_putstr_fd("sa\n", 1);
		if (order->prev->kind == O_PA)
			ft_putstr_fd("pa\n", 1);
		if (order->prev->kind == O_PB)
			ft_putstr_fd("pb\n", 1);
		rr_flag = check_print_rr(order);
		rrr_flag = check_print_rrr(order);
		if (rr_flag || rrr_flag)
			order = order->prev;
		order = order->prev;
	}
}
