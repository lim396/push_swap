/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:21:56 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:21:58 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_listack *stack, int size)
{
	if (is_sorted(stack->a))
		return ;
	if (size == 1)
		return ;
	if (size <= 3)
		less_than_three_sort(stack, stack->order, size);
	if (size <= 5)
		less_than_five_sort(stack, size);
	else
		medium_rare_sort(stack, size);
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
	stack.order = new_order_sentinel();
	if (stack.a == NULL || stack.b == NULL || stack.order == NULL)
		error_handler(&stack);
	push_swap(&stack, stack_size);
	print_order(stack.order);
	order_list_free(stack.order);
	stack_free(stack.a);
	stack_free(stack.b);
	return (0);
}
