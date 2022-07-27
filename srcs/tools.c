/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:52:17 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/17 11:52:18 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	panic(char *error_message)
{
	ft_puterror(error_message);
	exit(0);
}

void	print_stacks(t_stacks *stacks)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	ft_printf("|A||B|\n");
	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
			ft_printf("|%d||%d|\n", stack_a->value, stack_b->value);
		else if (stack_a)
			ft_printf("|%d|| |\n", stack_a->value);
		else
			ft_printf("| ||%d|\n", stack_b->value);
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
}