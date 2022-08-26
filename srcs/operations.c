/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:39:39 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/13 14:39:42 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	output_operation(int row, t_style operation)
{
	static char	*operations[3][4] = {
	{"sa\n", "pa\n", "ra\n", "rra\n"},
	{"sb\n", "pb\n", "rb\n", "rrb\n"},
	{"ss\n", NULL, "rr\n", "rrr\n"}
	};

	ft_putstr(operations[row][operation]);
	return ;
}

void	swap(t_stacks **stacks, int decider, int output)
{
	int			temp;
	t_stack		*stack;

	if (decider == A || decider == BOTH)
		stack = (*stacks)->stack_a;
	else
		stack = (*stacks)->stack_b;
	temp = 0;
	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	if (output)
		output_operation(decider, s);
	if (decider == BOTH)
		swap(stacks, B, 0);
	return ;
}

void	push(t_stacks **stacks, int decider, int output)
{
	t_stack		*new_head;
	t_stack		**source_stack;
	t_stack		**dest_stack;

	if (decider == A)
	{
		dest_stack = &(*stacks)->stack_a;
		source_stack = &(*stacks)->stack_b;
	}
	else
	{
		dest_stack = &(*stacks)->stack_b;
		source_stack = &(*stacks)->stack_a;
	}
	if ((*source_stack) == NULL)
		return ;
	new_head = (*source_stack)->next;
	(*source_stack)->next = (*dest_stack);
	(*dest_stack) = (*source_stack);
	(*source_stack) = new_head;
	if ((*source_stack))
		(*source_stack)->back = NULL;
	if (output)
		output_operation(decider, p);
	return ;
}

void	rotate(t_stacks **stacks, int decider, int output)
{
	t_stack	*new_head;
	t_stack	*tail_ptr;
	t_stack	**stack;

	if (decider == A || decider == BOTH)
		stack = &(*stacks)->stack_a;
	else
		stack = &(*stacks)->stack_b;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new_head = (*stack)->next;
	tail_ptr = (*stack);
	while (tail_ptr->next)
		tail_ptr = tail_ptr->next;
	tail_ptr->next = (*stack);
	(*stack)->next = NULL;
	(*stack)->back = tail_ptr;
	(*stack) = new_head;
	(*stack)->back = NULL;
	if (output)
		output_operation(decider, r);
	if (decider == BOTH)
		rotate(stacks, B, 0);
	return ;
}

void	reverse_rotate(t_stacks **stacks, int decider, int output)
{
	t_stack	*second_last;
	t_stack	**stack;
	t_stack	*old_head;

	if (decider == A || decider == BOTH)
		stack = &(*stacks)->stack_a;
	else
		stack = &(*stacks)->stack_b;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_last = (*stack);
	old_head = (*stack);
	while (second_last->next->next)
		second_last = second_last->next;
	(*stack) = second_last->next;
	(*stack)->next = old_head;
	(*stack)->back = NULL;
	(*stack)->next->back = (*stack);
	second_last->next = NULL;
	if (output)
		output_operation(decider, rr);
	if (decider == BOTH)
		reverse_rotate(stacks, B, 0);
}
