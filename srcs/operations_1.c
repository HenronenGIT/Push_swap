/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:39:39 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/13 14:39:42 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first 2 elements at the top of stack */
// long	*swap(long *stack, long size)
// {
// 	long	temp;

// 	temp = 0;

// 	if (size > 1)
// 	{
// 		temp = stack[0];
// 		stack[0] = stack[1];
// 		stack[1] = temp;
// 	}
// 	return (stack);
// }
t_data	*swap(t_data *data)
{
	long	temp;

	temp = 0;
	if (data->size > 1)
	{
		temp = data->stack[0];
		data->stack[0] = data->stack[1];
		data->stack[1] = temp;
	}
	return (data);
}

/* 1 */
// long	*push_a(long *stack_a, long size_a, long *stack_b, long size_b)
// t_data	*push(t_data *dest, t_data *src)
void	push(t_data *destination, t_data *source)
{
	long	temp;
	long	i;
	
	i = 0;
	temp = 0;
	if (source->size == 0)
		return ;
	while (i <= destination->size)
	{
		temp = destination->stack[i];
		destination->stack[i] = source->stack[0];
		source->stack[0] = temp;
		i++;
	}
	destination->stack[i] = temp;
	source->stack[0] = 0;
}
