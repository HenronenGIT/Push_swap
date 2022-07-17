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

void	swap(t_stack **stack)
{
	int	temp;

	temp = 0;
	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	return ;
}

void	push(t_stack **dest_stack, t_stack **source_stack)
{
	t_stack	*temp;

	if (*source_stack == NULL)
		return ;
	temp = (*source_stack)->next;
	(*source_stack)->next = (*dest_stack);
	(*dest_stack) = (*source_stack);
	(*source_stack) = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*tail_ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new_head = (*stack)->next;
	tail_ptr = *stack;
	while (tail_ptr->next)
		tail_ptr = tail_ptr->next;
	tail_ptr->next = *stack;
	(*stack)->next = NULL;
	*stack = new_head;
	return ;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = *stack;
	second_last = *stack;
	while (tail->next)
		tail = tail->next;
	while (second_last->next->next)
		second_last = second_last->next;
	tail->next = *stack;
	second_last->next = NULL;
	*stack = tail;
	return ;
}
