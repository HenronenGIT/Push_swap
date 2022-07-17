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

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("A\tB\n");
	printf("-\t-\n");
	while (stack_a || stack_b)
	{	
		if (stack_a && stack_b)
			printf("%d\t%d\n", stack_a->value, stack_b->value);
		else if (stack_a)
			printf("%d\t \n", stack_a->value);
		else
			printf(" \t%d\n", stack_b->value);
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
}