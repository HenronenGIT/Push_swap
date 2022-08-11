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

/* Finds index from stack to certain value - starting from top */
int	fetch_index_from_top(t_stack *stack_a, t_chunks *chunks)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (ft_nbr_in_array(stack_a->value, chunks->array, chunks->array_size))
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (0); // temp

	// 	t_stack	*node_pointer;
	// int	i;

	// i = 0;
	// node_pointer = stack_a;
	// while (stack_a)
	// {
	// 	if (ft_nbr_in_array(node_pointer->value, chunks->array, chunks->array_size))
	// 		return (i);
	// 	node_pointer = node_pointer->next;
	// 	i++;
	// }
	// return (0); // temp
}

/* Finds index from stack to certain value - starting from bottom */
int	fetch_index_from_bottom(t_stack *stack_a, t_chunks *chunks)
{
	int	i;

	i = 0;
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		i++;
	}
	while (stack_a)
	{
		if (ft_nbr_in_array(stack_a->value, chunks->array, chunks->array_size))
			return (i);
		stack_a = stack_a->back;
		i--;
	}
	return (0); // temp
}

static int	option_1_need_less_moves(int index_1, int index_2, t_stacks *stacks)
{
	// Need to decrease "stack_size" everytime when pushin to B
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

void	move_value_to_top(int movable_index, t_stacks *stacks)
{
	int	middle_point;
	int	moves_needed;

	middle_point = stacks->stack_size / 2;
	if (movable_index < middle_point)
	{
		moves_needed = movable_index;
		while (moves_needed)
		{
			rotate(&stacks, A, 1);  
			moves_needed -= 1;
		}
	}
	else
	{
		moves_needed = stacks->stack_size - movable_index;
		while (moves_needed)
		{
			reverse_rotate(&stacks, A, 1);
			moves_needed -= 1;
		}

	}
}

/* Iterates trough stack and if first value is a smallest returns 1 */
static int	smallest_in_stack(t_stack *stack, int value)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	rotate_b_to_correct_spot(t_stacks *stacks)
{
	int	right_spot;

	right_spot = 0;
	if (!stacks->stack_b)
		return ;
	// if (FIRST_A < FIRST_B) // make better by searching do we need to rb or rrb
	// if (!smallest_in_stack(STACK_B, FIRST_B)) // make better by searching do we need to rb or rrb
	while (1)
	{

	if (right_spot)
		return ;
	if (FIRST_A > FIRST_B)
	{
		right_spot = 1;
		rotate(&stacks, B, 1);
	}
	if (right_spot && FIRST_A < FIRST_B)
		return ;
	// else
	}
		// return ;
	// rotate_b_to_correct_spot(stacks);
}

void	sort_stack(t_stacks *stacks, t_chunks *chunks)
{
	int	option_1_index;
	int	option_2_index;

	while (chunks)
	{
		if (STACK_A)
		{

			option_1_index = fetch_index_from_top(STACK_A, chunks);
			option_2_index = fetch_index_from_bottom(STACK_A, chunks);
			if (option_1_need_less_moves(option_1_index, option_2_index, stacks))
				move_value_to_top(option_1_index, stacks);
			else
				move_value_to_top(option_2_index, stacks);
			rotate_b_to_correct_spot(stacks);
			push(&stacks, B, 1);
		}
		else
			chunks = chunks->next;

		print_stacks(stacks);
	}

}
