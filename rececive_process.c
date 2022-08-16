/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rececive_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:22:19 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:22:21 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_and_set_flag(t_listack *stack, int flag, t_olist *order)
{
	ra(stack, order);
	if (flag == 0)
		flag = 1;
	return (flag);
}

int	rra_and_set_flag(t_listack *stack, int flag, t_olist *order)
{
	rra(stack, order);
	if (flag == 1)
		flag = 0;
	return (flag);
}

void	receiv_proc(t_listack *st, int *sa_flag, int *rra_flag, t_olist *order)
{
	if (st->a->next->next->val - st->a->next->val == 2)
		*sa_flag = 1;
	if (st->a->next->next->val - st->a->next->val == 1
		&& *sa_flag == 1 && *rra_flag == 0)
		*rra_flag = ra_and_set_flag(st, *rra_flag, order);
	if (st->a->next->val - st->a->prev->val == 1
		&& *sa_flag == 0 && *rra_flag == 1)
		*rra_flag = rra_and_set_flag(st, *rra_flag, order);
	if (st->a->next->next->val - st->a->next->val < 0)
	{
		sa(st, order);
		*sa_flag = 0;
		if (*rra_flag > 0)
			*rra_flag = rra_and_set_flag(st, *rra_flag, order);
	}
	if (st->a->next->next->val - st->a->next->val > 2)
		*rra_flag = ra_and_set_flag(st, *rra_flag, order);
}
