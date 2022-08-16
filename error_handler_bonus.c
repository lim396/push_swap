/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:20:20 by shongou           #+#    #+#             */
/*   Updated: 2022/08/16 16:20:21 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_handler(t_listack *stack)
{
	ft_putstr_fd("Error\n", 2);
	stack_free(stack->a);
	stack_free(stack->b);
	exit(1);
}
