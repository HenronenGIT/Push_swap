/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:49:42 by hmaronen          #+#    #+#             */
/*   Updated: 2022/08/22 15:49:58 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_stack(t_stacks *stacks)
{
	if (stack_in_ascending_order(stacks->stack_a))
		return ;
	if (stack_in_descending_order(stacks->stack_a))
	{
		swap(&stacks, A, 1);
		reverse_rotate(&stacks, A, 1);
	}
	else if (biggest_in_stack(stacks->stack_a, stacks->stack_a->value))
		rotate(&stacks, A, 1);
	else if (stacks->stack_a->value > stacks->stack_a->next->value)
		swap(&stacks, A, 1);
	else if (smallest_in_stack(stacks->stack_a, stacks->stack_a->value))
	{
		swap(&stacks, A, 1);
		rotate(&stacks, A, 1);
	}
	else if (biggest_in_stack(stacks->stack_a, stacks->stack_a->next->value))
		reverse_rotate(&stacks, A, 1);
}

void sort_5_stack(t_stacks *stacks)
{
	int	correct_index;

	correct_index = 0;
	correct_index = find_correct_spot_from_a(stacks->stack_b->value, stacks->stack_a);
	move_value_to_top(correct_index, stacks, A);
	push(&stacks, A, 1);
	if (!stacks->stack_b)
	{
		if (smallest_closer_to_top(stacks->stack_a, stacks->stack_size))
			while (!smallest_in_stack(stacks->stack_a, stacks->stack_a->value))
				rotate(&stacks, A, 1);
		else
			while (!smallest_in_stack(stacks->stack_a, stacks->stack_a->value))
				reverse_rotate(&stacks, A, 1);
		return ;
	}
	sort_5_stack(stacks);
}
