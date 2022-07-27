/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:54:28 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/19 16:54:28 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	*fetch_last_node(t_stack *list)
// {
// 	while (list->next)
// 		list = list->next;
// 	return (list);
// }

// t_stacks	*quick_short(t_stacks *stacks)
// {
// 	t_stack	*pivot;
// 	t_stack	*stack_a;
// 	t_stack	*iterator;

// 	iterator = NULL;
// 	pivot = NULL;
// 	stack_a = NULL;

// 	stack_a = stacks->stack_a;
// 	pivot = fetch_last_node(stacks->stack_a);
// 	while (stack_a)
// 	{
// 		if (iterator && stack_a->value <= pivot->value)
			
// 		else
// 			iterator = stack_a;
// 		stack_a = stack_a->next;
// 	}
// 	// printf("%d\n", pivot->value);
// 	return (stacks);
// }

int	a_in_order(t_stack *stack_a)
{
	t_stack	*node;

	node = stack_a;
	while (node->next)
	{
		if (node->value < node->next->value)
			node = node->next;
		else
			return (0);
			// panic("KO\n");
	}
	return (1);
	// ft_putstr("OK\n");
}

static int	smallest_in_stack(t_stack *stack_a, int value)
{
	while (stack_a->next)
	{
		if (value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	push_all_to_a(t_stacks *stacks)
{
	// while (stacks->stack_b)
	while (STACK_B)
		push(&stacks, A, 1);
}

int	last_node_value(t_stack *stack_a)
{
	while (stack_a->next)
		stack_a = stack_a->next;
	return (stack_a->value);
}

// t_stacks	*sort_stack(t_stacks *stacks)
void	sort_stack(t_stacks *stacks)
{
	/* Decide if recursion of while */

	// if (stack_in_order(stacks))
		// return (stacks);
	if (a_in_order(STACK_A))
	{
		push_all_to_a(stacks);
		return ;
	}
	else if (smallest_in_stack(STACK_A, FIRST_NODE))
		push(&stacks, B, 1);
	else if (FIRST_NODE > SECOND_NODE) // What happens if you but this only to if and not "else if"
		swap(&stacks, A, 1);
	else if (FIRST_NODE > last_node_value(STACK_A)) // Add last_node_value to variable to save from extra loopping
	 	reverse_rotate(&stacks, A, 1);
	//else if (FIRST_NODE < last_node_value())
	//	reverse_rotate(&stacks, A);
	else
		reverse_rotate(&stacks, A, 1);
		// rotate(&stacks, A, 1);
	if (stack_in_order(stacks))
		return ;
	sort_stack(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks		*stacks; 
	int				*valid_numbers;
	int				array_len;

	stacks = NULL;
	argv++;
	if (argc < 2)
		exit(1);
	argv = explode_arguments(argc, argv); // Might cause memory leak?
	valid_numbers = check_input(argv);
	create_stacks(valid_numbers, ft_count_pointers(argv), &stacks);
	if (stack_in_order(stacks))
	{
		ft_printf("0\n");
		return (0); // Free all
	}
	
	// stacks = quick_sort(stacks);
	// stacks = sort_stack(stacks);
	sort_stack(stacks);

	
	// print_stacks(stacks);
}