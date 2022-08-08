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

void	receive_proc(t_listack *sta, int *sa_flag, int *rra_flag, t_olist *order)
{
	if (sta->a->next->next->val - sta->a->next->val == 2)
		*sa_flag = 1;
	if (sta->a->next->next->val - sta->a->next->val == 1
			&& *sa_flag == 1 && *rra_flag == 0)
		*rra_flag = ra_and_set_flag(sta, *rra_flag, order);
	if (sta->a->next->val - sta->a->prev->val == 1
			&& *sa_flag == 0 && *rra_flag == 1)
		*rra_flag = rra_and_set_flag(sta, *rra_flag, order);
	if (sta->a->next->next->val - sta->a->next->val < 0)
	{
		sa(sta, order);
		*sa_flag = 0;
		if (*rra_flag > 0)
			*rra_flag = rra_and_set_flag(sta, *rra_flag, order);
	}
	if (sta->a->next->next->val - sta->a->next->val > 2)
		*rra_flag = ra_and_set_flag(sta, *rra_flag, order);
}
