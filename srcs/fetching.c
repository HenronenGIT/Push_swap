/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:43:53 by hmaronen          #+#    #+#             */
/*   Updated: 2022/08/23 16:43:54 by hmaronen         ###   ########.fr       */
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

int	fetch_biggest_index(t_stack *stack)
{
	int	biggest;
	int	index_of_biggest;
	int	index;

	index = 0;
	index_of_biggest = 0;
	biggest = stack->value;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			index_of_biggest = index;
		}
		index += 1;
		stack = stack->next;
	}
	return (index_of_biggest);
}

int	fetch_smallest_index(t_stack *stack)
{
	int	smallest;
	int	index_of_smallest;
	int	index;

	index = 0;
	index_of_smallest = 0;
	smallest = stack->value;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			index_of_smallest = index;
		}
		index += 1;
		stack = stack->next;
	}
	return (index_of_smallest);
}

int	fetch_smallest_value(t_stack *stack) // USE IT
{
	int	smallest;

	smallest = stack->value;
	while (stack)
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}
