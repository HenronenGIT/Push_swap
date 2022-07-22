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

void	test_push(t_stacks *stacks)
{
	ft_printf("#### stacks Before push() function ####\n");
	print_stacks(stacks);

	push(&stacks, A);
	ft_printf("#### push() A ####\n");
	print_stacks(stacks);

	push(&stacks, B);
	ft_printf("#### push() B ####\n");
	print_stacks(stacks);
	
	 push(&stacks, A);
	 ft_printf("#### push() A ####\n");
	 print_stacks(stacks);

	 push(&stacks, A);
	 ft_printf("#### push() A ####\n");
	 print_stacks(stacks);

	push(&stacks, B);
	ft_printf("#### push() B ####\n");
	print_stacks(stacks);

	push(&stacks, B);
	ft_printf("#### push() B ####\n");
	print_stacks(stacks);
}

void	test_swap(t_stacks *stacks)
{
	printf("#### Before swap function ####\n");
	print_stacks(stacks);
	swap(&stacks, A);
	printf("#### After swap function ####\n");
	print_stacks(stacks);
}

void	test_rotate(t_stacks *stacks)
{
	ft_printf("#### stacka Before rotate() function ####\n");
	print_stacks(stacks);
	rotate(&stacks, A);
	ft_printf("#### rotate() A ####\n");
	print_stacks(stacks);
	
	rotate(&stacks, A);
	ft_printf("#### rotate() A ####\n");
	print_stacks(stacks);

	rotate(&stacks, A);
	ft_printf("#### rotate() A ####\n");
	print_stacks(stacks);

	ft_printf("#### push() B ####\n");
	push(&stacks, B);
	push(&stacks, B);
	push(&stacks, B);
	print_stacks(stacks);

	ft_printf("#### rotate() B ####\n");
	rotate(&stacks, B);
	print_stacks(stacks);

	ft_printf("#### rotate() B ####\n");
	rotate(&stacks, B);
	print_stacks(stacks);

	ft_printf("#### rotate() B ####\n");
	rotate(&stacks, B);
	print_stacks(stacks);

	rotate(&stacks, A);
	ft_printf("#### rotate() A ####\n");
	print_stacks(stacks);
}

void	test_reverse_rotate(t_stacks *stacks)
{
	ft_printf("#### stacks Before reverse_rotate() function ####\n");
	print_stacks(stacks);

	reverse_rotate(&stacks, A);
	ft_printf("#### reverse_rotate() A ####\n");
	print_stacks(stacks);
	
	reverse_rotate(&stacks, A);
	ft_printf("#### reverse_rotate() A ####\n");
	print_stacks(stacks);

	reverse_rotate(&stacks, A);
	ft_printf("#### reverse_rotate() A ####\n");
	print_stacks(stacks);

	ft_printf("#### push() B 3x ####\n");
	push(&stacks, B);
	push(&stacks, B);
	push(&stacks, B);
	print_stacks(stacks);

	ft_printf("#### reverse_rotate() B ####\n");
	reverse_rotate(&stacks, B);
	print_stacks(stacks);
	
	ft_printf("#### reverse_rotate() B ####\n");
	reverse_rotate(&stacks, B);
	print_stacks(stacks);

	ft_printf("#### reverse_rotate() B ####\n");
	reverse_rotate(&stacks, B);
	print_stacks(stacks);

	ft_printf("#### reverse_rotate() B ####\n");
	reverse_rotate(&stacks, B);
	print_stacks(stacks);

	ft_printf("#### reverse_rotate() B ####\n");
	reverse_rotate(&stacks, B);
	print_stacks(stacks);
}

int	main(void)
{
	t_stacks	*stacks;

	t_stack		*stack_a;
	t_stack		*node_a_1;
	t_stack		*node_a_2;
	t_stack		*node_a_3;

	t_stack		*stack_b;
	t_stack		*node_b_1;
	t_stack		*node_b_2;
	t_stack		*node_b_3;

	t_stack	*iterator;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	
	stacks->stack_a = (t_stack *)malloc(sizeof(t_stack));
	node_a_1 = (t_stack *)malloc(sizeof(t_stack));
	node_a_2 = (t_stack *)malloc(sizeof(t_stack));
	node_a_3 = (t_stack *)malloc(sizeof(t_stack));

	stacks->stack_a->next = node_a_1;
	stacks->stack_a->next->next = node_a_2;
	stacks->stack_a->next->next->next = node_a_3;
	stacks->stack_a->next->next->next->next = NULL;

	stacks->stack_b = NULL;

	iterator = stacks->stack_a;
	while (iterator)
	{
		iterator->value = rand() % 100;
		iterator = iterator->next;
	}

	/* Swap function */
		// test_swap(stacks);
	/* Push function */
		// test_push(stacks);
	// Rotate function
		// test_rotate(stacks);
	/* reverse_rotate function */
		test_reverse_rotate(stacks);
	/* Free */
	// while (stack_a)
	// {
	// 	free(stack_a);
	// 	stack_a = stack_a->next;
	// }
	// while (stack_b)
	// {
	// 	free(stack_b);
	// 	stack_b = stack_b->next;
	// }
}