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

int	list_size(t_stack *stack) // can be added to libft with void style
{
	int	node_count;

	node_count = 1;
	while (stack->next)
	{
		node_count += 1;
		stack = stack->next;
	}
	return (node_count);
}

// void	move_value_to_top(int movable_index, t_stacks *stacks)
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
	if (movable_index < middle_point)
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

static int	biggest_in_stack(t_stack *stack, int value)
{
	while (stack->next)
	{
		if (value < stack->next->value)
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
			// panic("KO\n");
	}
	return (1);
	// ft_putstr("OK\n");
}

// int	find_place_from_b(t_stacks *stacks)
// {
// 	t_stack	*node_ptr;
// 	int	rotations_needed;

// 	rotations_needed = 1;
// 	node_ptr = STACK_B;
// 	if (!node_ptr || !node_ptr->next)
// 		return (0);
// 	while (STACK_B)
// 	{
// 		if (FIRST_A > node_ptr->value && node_ptr->next && FIRST_A < node_ptr->next->value)
// 			return (rotations_needed);
// 		else
// 			node_ptr = node_ptr->next;
// 		rotations_needed += 1;
// 	}
// 	return (rotations_needed);
// }

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

// int	find_correct_spot(t_stacks *stacks)
int	find_correct_spot(int first_a_value, t_stack *stack)
{
	int	correct_index;
	int	i;
	int	last_value;

	last_value = 0;
	i = 0;
	correct_index = 0;
	while (stack)
	{
		if (first_a_value > stack->value && last_value < stack->value)
		{
			correct_index = i;
			last_value = stack->value;
		}


		// if (first_a_value > stack->value && stack->next && stack->value < stack->next->value && first_a_value < stack->next->value)
		// {
		// 	correct_index = i;
		// 	last_value = stack->value;
		// }
		// else if (first_a_value > stack->value && stack->next && first_a_value > stack->next->value && stack->value > last_value)
		// 	correct_index = i;
		// else if (STACK_A->next && smallest_in_stack(STACK_A, FIRST_A) && biggest_in_stack(STACK_B, stack->value))
		// 	return (i);
		// else if (first_a_value < FIRST_B && stack->next && first_a_value < stack->next->value && last_value < stack->value)
		// {
		// 	correct_index = i;
		// 	last_value = stack->value;
		// }
		i += 1;
		stack = stack->next;
	}
	return (correct_index);
}

void	rotate_b_to_correct_spot(t_stacks *stacks)
{
	// Trying first to sort stack to ASCENDING ORDER - like in the guide
	int	correct_index;

	correct_index = 0;
	/* Already in correct spot function */
	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;	
	// if (FIRST_A < FIRST_B && FIRST_A > last_value(STACK_B))
		// return ;
	if (FIRST_A < FIRST_B && smallest_in_stack(STACK_B, FIRST_B))
		return ;
	// if (stack_in_ascending_order(STACK_B) && FIRST_A > FIRST_B && FIRST_A > last_value(STACK_B))
		// return ;
	if (stack_in_descending_order(STACK_B) && FIRST_A > FIRST_B && FIRST_A > last_value(STACK_B))
		return ;
	if (stack_in_descending_order(STACK_B) && FIRST_A > last_value(STACK_B) && smallest_in_stack(STACK_B, FIRST_B))
		return ;
	/*  */	
	correct_index = find_correct_spot(FIRST_A, STACK_B);

	move_value_to_top(correct_index, stacks, B);
	// print_stacks(stacks);
	//rotate(&stacks, B, 1);
	//print_stacks(stacks);
	//rotate_b_to_correct_spot(stacks);
}

void	push_all_to_a(t_stacks *stacks)
{
	while (STACK_B)
		push(&stacks, A, 1);
}

// int	stack_contains_chunk_value(t_stack *stack_a, int *chunk_array, int array_size)
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

	int	debug_counter; //temp

	debug_counter = 0;

	// mayby need iterator for chunks so we dont lose head on linked list
	while (chunks)
	{
		// print_stacks(stacks);

		if (stack_contains_chunk_value(stacks->stack_a, chunks))
		{
			option_1_index = fetch_index_from_top(STACK_A, chunks);
			option_2_index = fetch_index_from_bottom(STACK_A, chunks);
			if (option_1_need_less_moves(option_1_index, option_2_index, stacks))
				move_value_to_top(option_1_index, stacks, A);
			else
				move_value_to_top(option_2_index, stacks, A);
			rotate_b_to_correct_spot(stacks);
			push(&stacks, B, 1);
		}
		else
			chunks = chunks->next;
		// print_stacks(stacks);
		debug_counter += 1;
	}
		// print_stacks(stacks);
	while (STACK_B)
	{
		if (!biggest_in_stack(STACK_B, FIRST_B)) // Make better to find if bigger is closer to top than bottom
			reverse_rotate(&stacks, B, 1);
		else
			push(&stacks, A, 1);
	}
	// print_stacks(stacks);
}
