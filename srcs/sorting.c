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

int		b_in_order(t_stack *stack_b)
{
	t_stack	*node;

	node = stack_b;
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

	int	rotations_needed;
	int	i;

	i = 0;
	rotations_needed = 0;
	while (stack)
	{
		if (first_a_value > stack->value && stack->next->value > first_a_value)
			rotations_needed += 1;
		stack = stack->next;

	}
	// while (stack)
	// {
	// 		rotations_needed += 1;
	// 	i += 1;
	// 	stack = stack->next;
	// }
	return (rotations_needed);
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

void	rotate_b_to_correct_spot(t_stacks *stacks)
{
	// Trying first to sort stack to ASCENDING ORDER - like in the guide
	int	rotation_count;
	int	test;

	test = 0;
	rotation_count = 0;
	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;	
	if (FIRST_A < FIRST_B && FIRST_A > last_value(STACK_B))
		return ;
	if (FIRST_A < FIRST_B && smallest_in_stack(STACK_B, FIRST_B))
		return ;
	if (stack_in_ascending_order(STACK_B) && FIRST_A > FIRST_B && FIRST_A > last_value(STACK_B))
		return ;
	if (b_in_order(STACK_B) && FIRST_A > last_value(STACK_B) && smallest_in_stack(STACK_B, FIRST_B))
		return ;
	
	rotation_count = find_correct_spot(FIRST_A, STACK_B);
	test = list_size(STACK_B) / 2;
	if (rotation_count > list_size(STACK_B) / 2)
		while (--rotation_count + 1)
			reverse_rotate(&stacks, B, 1);
	else
		while (--rotation_count + 1)
			rotate(&stacks, B, 1);


		//CHECK IF ANY PERMUTATION USES THIS STATEMENT
		//Atm only last value of a is using it
	// if (biggest_in_stack(STACK_A, FIRST_A) && biggest_in_stack(STACK_B, FIRST_B))
		// return ;

	// rotate(&stacks, B, 1);
	print_stacks(stacks);
	// rotate_b_to_correct_spot(stacks);
}

void	push_all_to_a(t_stacks *stacks)
{
	while (STACK_B)
		push(&stacks, A, 1);
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
	while (STACK_B)
	{
		if (!biggest_in_stack(STACK_B, FIRST_B)) // Make better to find if bigger is closer to top than bottom
			rotate(&stacks, B, 1);
		else
			push(&stacks, A, 1);
		// print_stacks(stacks);
	}
}
