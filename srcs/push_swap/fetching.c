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

/*
	Finds values index from the stack - starting from top.
*/
int	fetch_index_from_top(t_stack *stack, t_chunks *chunks)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (ft_nbr_in_array(stack->value, chunks->array, chunks->array_size))
			return (index);
		stack = stack->next;
		index++;
	}
	return (0);
}

/*
	Finds values index from the stack - starting from top.
*/
int	fetch_index_from_bottom(t_stack *stack_a, t_chunks *chunks)
{
	int	index;

	index = 0;
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		index++;
	}
	while (stack_a)
	{
		if (ft_nbr_in_array(stack_a->value, chunks->array, chunks->array_size))
			return (index);
		stack_a = stack_a->back;
		index--;
	}
	return (0);
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
