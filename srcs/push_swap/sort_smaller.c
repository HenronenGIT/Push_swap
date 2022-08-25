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

void	rotate_many(int moves, t_stacks **stacks, int stack, int operation)
{
	while (moves)
	{
		if (stack == A && operation == ROTATE)
			rotate(stacks, A, 1);
		else if (stack == A && operation == REVERSE_ROTATE)
			reverse_rotate(stacks, A, 1);
		else if (stack == B && operation == ROTATE)
			rotate(stacks, B, 1);
		else if (stack == B && operation == REVERSE_ROTATE)
			reverse_rotate(stacks, B, 1);
		moves -= 1;
	}
	return ;
}

static int	find_spot_from_a(int first_a_value, t_stack *stack)
{
	int	i;
	int	*last_value;
	int	correct_index;

	i = 0;
	last_value = NULL;
	correct_index = 0;
	if (biggest_in_stack(stack, first_a_value))
		return (fetch_smallest_index(stack));
	while (stack)
	{
		if (first_a_value < stack->value)
		{
			if ((last_value && *last_value >= stack->value) || !last_value)
			{
				correct_index = i;
				last_value = (&stack->value);
			}
		}
		i += 1;
		stack = stack->next;
	}
	return (correct_index);
}

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

void	sort_5_stack(t_stacks *stacks)
{
	int	correct_index;

	correct_index = 0;
	correct_index = find_spot_from_a(stacks->stack_b->value, stacks->stack_a);
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
