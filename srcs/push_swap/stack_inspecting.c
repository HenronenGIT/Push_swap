/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inspecting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:47:29 by hmaronen          #+#    #+#             */
/*   Updated: 2022/08/24 10:47:30 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Inspects if recevied stack is in ascending order.
*/
int	stack_in_ascending_order(t_stack *stack)
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

/*
	Inspects if recevied stack is in descending order.
*/
int	stack_in_descending_order(t_stack *stack)
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

/*
	Inspects if "value" is biggest in the stack recevied as a parameter.
*/
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

/*
	Iterates trough stack and if first value is a smallest returns 1
*/
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

/*
	Checks if smallest value of the stack is closer to top.
	If it is returns 1.
*/
int	smallest_closer_to_top(t_stack *stack, int stack_size)
{
	int	index_of_smallest;

	index_of_smallest = fetch_smallest_index(stack);
	if (index_of_smallest < (stack_size / 2))
		return (1);
	return (0);
}
