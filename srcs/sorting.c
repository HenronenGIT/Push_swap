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

int smallest_closer_to_top(t_stack *stack, int stack_size)
{
	int index_of_smallest;
	int i;

	i = 0;
	index_of_smallest = fetch_smallest_index(stack);
	if (index_of_smallest < (stack_size / 2))
		return (1);
	return (0);
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

int	list_size(t_stack *stack) // can be added to libft with casting to void?
{
	int	node_count;

	node_count = 1;
	if (!stack)
		return (0);
	while (stack->next)
	{
		node_count += 1;
		stack = stack->next;
	}
	return (node_count);
}

void	move_value_to_top(int movable_index, t_stacks *stacks, int decider)
{
	int		middle_point;
	int		moves_needed;
	t_stack *stack;

	// middle_point = stacks->stack_size / 2;
	if (decider == A)
		stack = stacks->stack_a;
	else
		stack = stacks->stack_b;
	middle_point = list_size(stack) / 2;
	// if (movable_index < middle_point)
	if (movable_index <= middle_point)
	{
		moves_needed = movable_index;
		while (moves_needed)
		{
			if (decider == A)
				rotate(&stacks, A, 1);
			else
				rotate(&stacks, B, 1);
			moves_needed -= 1;
		}
	}
	else
	{
		moves_needed = list_size(stack) - movable_index;
		while (moves_needed)
		{
			if (decider == A)
				reverse_rotate(&stacks, A, 1);
			else
				reverse_rotate(&stacks, B, 1);
			// reverse_rotate(&stacks, A, 1);
			moves_needed -= 1;
		}
	}
}

/* Iterates trough stack and if first value is a smallest returns 1 */
int	smallest_in_stack(t_stack *stack, int value)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (value > stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	biggest_in_stack(t_stack *stack, int value)
{
	while (stack)
	{
		if (value < stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	last_value(t_stack *stack)
{
	// Check if seg faults
	while (stack->next)
		stack = stack->next;
	return (stack->value);
}

int		stack_in_descending_order(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node->next)
	{
		if (node->value > node->next->value)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

int		stack_in_ascending_order(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node->next)
	{
		if (node->value < node->next->value)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

int	find_correct_spot(int first_a_value, t_stack *stack)
{
	int	i;
	int	*last_value;
	int	correct_index;

	i = 0;
	last_value = NULL;
	correct_index = 0;
	// if (smallest_in_stack(stack, first_a_value))
		// return(fetch_biggest_index(stack));
	while (stack)
	{
		if (first_a_value > stack->value)
			if ((last_value && *last_value <= stack->value) || !last_value)
			{
				correct_index = i;
				last_value = (&stack->value);
			}
		i += 1;
		stack = stack->next;
	}
	return (correct_index);
}

int	find_correct_spot_from_a(int first_a_value, t_stack *stack)
{
	int	i;
	int	*last_value;
	int	correct_index;

	i = 0;
	last_value = NULL;
	correct_index = 0;
	if (biggest_in_stack(stack, first_a_value))
		return(fetch_smallest_index(stack));
	while (stack)
	{
		// if (first_a_value > stack->value &&
		// (!last_value || last_value && (*last_value <= stack->value)))
		if (first_a_value < stack->value)
			if ((last_value && *last_value >= stack->value) || !last_value)
			{
				correct_index = i;
				last_value = (&stack->value);
			}
		i += 1;
		stack = stack->next;
	}
	return (correct_index);
}

void	rotate_b_to_correct_spot(t_stacks *stacks)
{
	int	correct_index;

	correct_index = 0;
	// print_stacks(stacks);
	/* Already in correct spot function */
	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;
	if (smallest_in_stack(stacks->stack_b, stacks->stack_a->value))
		correct_index = fetch_biggest_index(stacks->stack_b);
	else
		correct_index = find_correct_spot(FIRST_A, STACK_B);

	move_value_to_top(correct_index, stacks, B);
}

void	push_all_to_a(t_stacks *stacks)
{
	//optimize that bigger is closes to top
	// while (STACK_B)
	// {
		if (smallest_closer_to_top(stacks->stack_b, stacks->stack_size))
			while (!biggest_in_stack(STACK_B, FIRST_B)) // Make better to find if bigger is closer to top than bottom
				rotate(&stacks, B, 1);
		else
			while (!biggest_in_stack(STACK_B, FIRST_B)) // Make better to find if bigger is closer to top than bottom
				reverse_rotate(&stacks, B, 1);
	while (STACK_B)
	{
		// print_stacks(stacks);
		push(&stacks, A, 1);
	}
	// }
}

int	stack_contains_chunk_value(t_stack *stack_a, t_chunks *chunks)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (ft_nbr_in_array(stack_a->value, chunks->array, chunks->array_size))
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	sort_stack(t_stacks *stacks, t_chunks *chunks)
{
	int	option_1_index;
	int	option_2_index;

	while (chunks)
	{
		if (stack_contains_chunk_value(stacks->stack_a, chunks))
		{
			// print_stacks(stacks);
			option_1_index = fetch_index_from_top(STACK_A, chunks);
			option_2_index = fetch_index_from_bottom(STACK_A, chunks);
			if (option_1_need_less_moves(option_1_index, option_2_index, stacks))
				move_value_to_top(option_1_index, stacks, A);
			else
				move_value_to_top(option_2_index, stacks, A);
			if (list_size(stacks->stack_b) == 2
				&& stacks->stack_b->next
				&& stacks->stack_b->value < stacks->stack_b->next->value)
					swap(&stacks, A, 1);
			rotate_b_to_correct_spot(stacks);
			push(&stacks, B, 1);
		}
		else
			chunks = chunks->next;
	}
	push_all_to_a(stacks);
}
