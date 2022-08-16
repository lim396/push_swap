/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:18:22 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:18:26 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	exe_order(t_listack *stack, char *order)
{
	if (ft_strncmp(order, "pa\n", 3) == 0)
		pa(stack);
	else if (ft_strncmp(order, "pb\n", 3) == 0)
		pb(stack);
	else if (ft_strncmp(order, "sa\n", 3) == 0)
		sa(stack->a);
	else if (ft_strncmp(order, "sb\n", 3) == 0)
		sb(stack->b);
	else if (ft_strncmp(order, "ra\n", 3) == 0)
		ra(stack->a);
	else if (ft_strncmp(order, "rb\n", 3) == 0)
		rb(stack->b);
	else if (ft_strncmp(order, "rr\n", 3) == 0)
		rr(stack->a, stack->b);
	else if (ft_strncmp(order, "rra\n", 4) == 0)
		rra(stack->a);
	else if (ft_strncmp(order, "rrb\n", 4) == 0)
		rrb(stack->b);
	else if (ft_strncmp(order, "rrr\n", 4) == 0)
		rrr(stack->a, stack->b);
	else
	{
		free(order);
		error_handler(stack);
	}
}

void	read_orders(t_listack *stack)
{
	char	*order;

	while (1)
	{
		order = get_next_line(0);
		if (order == NULL)
			return ;
		exe_order(stack, order);
		free(order);
	}
}

int	main(int argc, char **argv)
{
	t_listack	stack;
	int			*stack_arry;
	int			stack_size;

	if (!args_error_check(argc, argv))
		print_error();
	stack_size = count_elem(argv);
	if (stack_size >= INT_MAX)
		print_error();
	stack_arry = create_arry(argv, stack_size);
	if (stack_arry == NULL)
		print_error();
	coordinate_compression(stack_arry, stack_size);
	stack.a = create_stacklist(stack_arry, stack_size);
	stack.b = create_stacklist(NULL, 0);
	free(stack_arry);
	if (stack.a == NULL || stack.b == NULL)
		error_handler(&stack);
	read_orders(&stack);
	judge_sort(stack.a, stack.b);
	stack_free(stack.a);
	stack_free(stack.b);
	return (0);
}
