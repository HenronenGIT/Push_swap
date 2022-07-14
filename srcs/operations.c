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

t_stack	*swap(t_stack *stack) // Change to void func?
{
	long	temp;
	t_stack	*temp_ptr;

	temp = 0;
	if (!stack || !stack->next)
		return (stack);
	else
		temp_ptr = stack->next;
	temp = stack->value;
	stack->value = temp_ptr->value;
	temp_ptr->value = temp;
	return (stack);
}

void	push(t_stack **dest_stack, t_stack **source_stack)
{
	t_stack	*temp;

	if (source_stack == NULL)
		return ;
	temp = (*source_stack)->next;
	(*source_stack)->next = (*dest_stack);
	(*dest_stack) = (*source_stack);
	(*source_stack) = temp;
}

t_stack	*rotate(t_stack *stack)
{
	t_stack	*second_ptr;
	t_stack	*tail_ptr;

	if (stack->next == NULL)
		return (stack);
	second_ptr = stack->next;
	tail_ptr = stack;
	while (tail_ptr->next)
		tail_ptr = tail_ptr->next;
	tail_ptr->next = stack;
	stack->next = NULL;
	return (second_ptr);
}

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*tail_ptr;

	temp = stack;
	while (stack->next->next != NULL)
		stack = stack->next;
	tail_ptr = stack->next;
	tail_ptr->next = temp;
	stack->next = NULL;
	stack = tail_ptr;
	return (stack);
}
