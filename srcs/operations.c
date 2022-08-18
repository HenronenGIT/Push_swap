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

// void	output_instruction()
// {

// }

void	swap(t_stacks **stacks, int decider, int output)
{
	int		temp;
	t_stack	*stack;

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
	// if (output)
		// output_instruction();
	if (output && decider == A)
		ft_putstr("sa\n");
	else if (output && decider == B)
		ft_putstr("sb\n");
	else if (output && decider == BOTH)
		ft_putstr("ss\n");
	if (decider == BOTH)
		swap(stacks, B, 0);
	return ;
}

// void	push(t_stacks **stacks, int decider)
void	push(t_stacks **stacks, int decider, int output)
{
	t_stack	*new_head;
	t_stack	**source_stack;
	t_stack	**dest_stack;

	// if (output && decider == A)
	// 	ft_putstr("pa\n");
	// ft_putstr("pb\n");
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
	(*source_stack)->next = (*dest_stack); // useless?

	// (*source_stack)->back = NULL;

	(*dest_stack) = (*source_stack);
	(*source_stack) = new_head;
	if ((*source_stack))
		(*source_stack)->back = NULL; // NEW
	if (output && decider == A)
		ft_putstr("pa\n");
	else if (output && decider == B)
		ft_putstr("pb\n");
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

	// tail_ptr->back = NULL;
	
	(*stack)->next = NULL;

	(*stack)->back = tail_ptr;
	(*stack) = new_head;
	(*stack)->back = NULL;
	if (output && decider == A)// Mayby to own fucntion to save space
		ft_putstr("ra\n");
	if (output && decider == B)
		ft_putstr("rb\n");
	if (decider == BOTH)
	{
		ft_putstr("rr\n");
		rotate(stacks, B, 0);
	}
	return ;
}

// void	reverse_rotate(t_stacks **stacks, int decider)
void	reverse_rotate(t_stacks **stacks, int decider, int output)
{
	t_stack	*second_last;
	t_stack	*tail;
	t_stack	**stack;

	if (decider == A || decider == BOTH)
		stack = &(*stacks)->stack_a;
	else
		stack = &(*stacks)->stack_b;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = (*stack);
	second_last = (*stack);
	while (tail->next)
		tail = tail->next;
	while (second_last->next->next)
		second_last = second_last->next;
	tail->next = (*stack);
	second_last->next = NULL;
	(*stack) = tail;
	if (output && decider == A)
		ft_putstr("rra\n");
	else if (output && decider == B)
		ft_putstr("rrb\n");
	if (decider == BOTH)
	{
		ft_putstr("rrr\n");
		reverse_rotate(stacks, B, 0);
	}
	return ;
}
