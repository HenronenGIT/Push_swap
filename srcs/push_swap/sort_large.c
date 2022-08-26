/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:22:47 by hmaronen          #+#    #+#             */
/*   Updated: 2022/08/10 13:22:48 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Compares indexes of 2 values found from stack and calculates which one
	needs lesser operations to get that value top of the stack.
*/
static int	option_1_need_less_moves(int index_1, int index_2, t_stacks *stacks)
{
	int	middle_point;
	int	moves_needed_1;
	int	moves_needed_2;

	middle_point = stacks->stack_size / 2;
	if (index_1 > middle_point)
		moves_needed_1 = index_1;
	else
		moves_needed_1 = stacks->stack_size - index_1;
	if (index_2 > middle_point)
		moves_needed_2 = index_2;
	else
		moves_needed_2 = stacks->stack_size - index_2;
	if (moves_needed_1 >= moves_needed_2)
		return (1);
	return (0);
}

/*
	Iterates trought stack linked list and finds "corrext_index".
	Correct index is place where "first_a_value" need to be placed so stack
	stays in order.
*/
static int	find_correct_spot(int first_a_value, t_stack *stack)
{
	int	i;
	int	*last_value;
	int	correct_index;

	i = 0;
	last_value = NULL;
	correct_index = 0;
	while (stack)
	{
		if (first_a_value > stack->value)
		{
			if ((last_value && *last_value <= stack->value) || !last_value)
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

static void	rotate_b_to_correct_spot(t_stacks *stacks)
{
	int	correct_i;

	correct_i = 0;
	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;
	if (smallest_in_stack(stacks->stack_b, stacks->stack_a->value))
		correct_i = fetch_biggest_index(stacks->stack_b);
	else
		correct_i = find_correct_spot(stacks->stack_a->value, stacks->stack_b);
	move_value_to_top(correct_i, stacks, B);
}

/*
	Function checks if stack_a is containing any values found from
	chunks->array.
*/
static int	stack_contains_chunk_value(t_stack *stack_a, t_chunks *chunks)
{
	while (stack_a)
	{
		if (ft_nbr_in_array(stack_a->value, chunks->array, chunks->array_size))
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

/*
	Sorts all the stacks which are larger than 5.
	Fetches 2 indexes which are in the chunk array.
	Rotates that index to top of the stack which needs less moves.
	Pushes that value to B.
	After A stack is empty pushes all values from B to A.
*/
void	sort_big_stacks(t_stacks *stacks, t_chunks *chunks)
{
	int	index_1;
	int	index_2;

	while (chunks)
	{
		if (stack_contains_chunk_value(stacks->stack_a, chunks))
		{
			index_1 = fetch_index_from_top(stacks->stack_a, chunks);
			index_2 = fetch_index_from_bottom(stacks->stack_a, chunks);
			if (option_1_need_less_moves(index_1, index_2, stacks))
				move_value_to_top(index_1, stacks, A);
			else
				move_value_to_top(index_2, stacks, A);
			rotate_b_to_correct_spot(stacks);
			push(&stacks, B, 1);
		}
		else
			chunks = chunks->next;
	}
	push_all_to_a(stacks);
}
