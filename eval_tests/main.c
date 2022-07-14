/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:01:19 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/13 15:01:22 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void	print_stack(t_stack *stack)
{
	while (stack)
	{	
		printf("%ld\n", stack->value);
		stack = stack->next;
	}
}

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*node_a_1;
	t_stack	*node_a_2;
	t_stack	*node_a_3;

	t_stack	*stack_b;
	t_stack	*node_b_1;
	t_stack	*node_b_2;
	t_stack	*node_b_3;

	t_stack	*iterator;
	
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	node_a_1 = (t_stack *)malloc(sizeof(t_stack));
	node_a_2 = (t_stack *)malloc(sizeof(t_stack));
	node_a_3 = (t_stack *)malloc(sizeof(t_stack));

	stack_b = (t_stack *)malloc(sizeof(t_stack));
	node_b_1 = (t_stack *)malloc(sizeof(t_stack));
	node_b_2 = (t_stack *)malloc(sizeof(t_stack));
	node_b_3 = (t_stack *)malloc(sizeof(t_stack));

	stack_a->next = node_a_1;
	node_a_1->next = node_a_2;
	node_a_2->next = node_a_3;
	node_a_3->next = NULL;

	stack_b->next = node_b_1;
	node_b_1->next = node_b_2;
	node_b_2->next = node_b_3;
	node_b_3->next = NULL;

	iterator = stack_a;
	while (iterator)
	{
		iterator->value = rand() % 100;
		iterator = iterator->next;
	}
	iterator = stack_b;
	while (iterator)
	{
		iterator->value = rand() % 100;
		iterator = iterator->next;
	}
	printf("#### Before swap function ####\n");
	print_stack(stack_a);
	stack_a = swap(stack_a);
	printf("#### After swap function ####\n");
	print_stack(stack_a);

	printf("#### stack_a Before push() function ####\n");
	print_stack(stack_a);
	printf("#### stack_b Before push() function ####\n");
	print_stack(stack_b);
	push(&stack_a, &stack_b);
	printf("#### stack_a After push() function ####\n");
	print_stack(stack_a);
	printf("#### stack_b After push() function ####\n");
	print_stack(stack_b);
	while (stack_a)
	{
		free(stack_a);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		free(stack_b);
		stack_b = stack_b->next;
	}
}