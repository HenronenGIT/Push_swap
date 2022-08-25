/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulating.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:07:16 by hmaronen          #+#    #+#             */
/*   Updated: 2022/08/24 12:07:17 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_value_to_top(int movable_index, t_stacks *stacks, int decider)
{
	int		middle_point;
	int		moves_needed;
	t_stack	*stack;

	if (decider == A)
		stack = stacks->stack_a;
	else
		stack = stacks->stack_b;
	middle_point = list_size(stack) / 2;
	if (movable_index <= middle_point)
	{
		moves_needed = movable_index;
		if (decider == A)
			rotate_many(moves_needed, &stacks, A, ROTATE);
		else
			rotate_many(moves_needed, &stacks, B, ROTATE);
	}
	else
	{
		moves_needed = list_size(stack) - movable_index;
		if (decider == A)
			rotate_many(moves_needed, &stacks, A, REVERSE_ROTATE);
		else
			rotate_many(moves_needed, &stacks, B, REVERSE_ROTATE);
	}
}

void	push_all_to_a(t_stacks *stacks)
{
	if (smallest_closer_to_top(stacks->stack_b, stacks->stack_size))
		while (!biggest_in_stack(stacks->stack_b, stacks->stack_b->value))
			rotate(&stacks, B, 1);
	else
		while (!biggest_in_stack(stacks->stack_b, stacks->stack_b->value))
			reverse_rotate(&stacks, B, 1);
	while (stacks->stack_b)
		push(&stacks, A, 1);
}
