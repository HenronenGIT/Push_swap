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

int		a_in_order(t_stack *stack_a)
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
int		b_in_order(t_stack *stack_b)
{
	t_stack	*node;

	node = stack_b;
	while (node->next)
	{
		if (node->value > node->next->value)
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

int		last_value_bigger(t_stack *stack)
{
	int	first_value;

	if (!stack)
		return (0);
	first_value = stack->value;
	while (stack->next)
		stack = stack->next;
	if (first_value < stack->value)
		return (1);
	return (0);
}

int	smallest_closer_to_top(t_stack *stack_a, int stack_size)
{
	int	smallest_index;
	int	smallest_value;
	int	i;

	i = 0;
	smallest_value = stack_a->value;
	smallest_index = 0;
	while (stack_a)
	{
		if (stack_a->value < smallest_value)
		{
			smallest_value = stack_a->value;
			smallest_index = i;
		}
		i += 1;
		stack_a = stack_a->next;
	}
	if (smallest_index < (stack_size / 2))
		return (1);
	return (0);
}

t_stacks	*sort_b_stack(t_stacks *stacks)
{
	// print_stacks(stacks);
	if (b_in_order(STACK_B))
		return (stacks);
	else if (smallest_in_stack(STACK_B, FIRST_B))
		rotate(&stacks, B, 1);
	else if (FIRST_B < SECOND_B)
		swap(&stacks, B, 1);
	else if (last_value_bigger(STACK_B))
		rotate(&stacks, B, 1);
	else
		rotate(&stacks, B, 1);
	if (b_in_order(STACK_B))
		return (stacks);
	return (sort_b_stack(stacks));
}

void	sort_stack(t_stacks *stacks)
{
	// if (a_in_order(STACK_A) && b_in_order(STACK_B))
	if (a_in_order(STACK_A) && FIRST_A >= HALF_VALUE)
	{
		stacks = sort_b_stack(stacks); // check if even need return?
		push_all_to_a(stacks);
		return ;
	}
	if (FIRST_A < HALF_VALUE)
		push(&stacks, B, 1);
	else if (smallest_in_stack(STACK_A, FIRST_A))
		push(&stacks, B, 1);
		
	else if (FIRST_A < SECOND_A && STACK_B && stacks->stack_b->next && FIRST_B < SECOND_B)
		reverse_rotate(&stacks, BOTH, 1); // add macro or define "ROTATE BOTH"
	else if (FIRST_A > SECOND_A && STACK_B &&  stacks->stack_b->next && FIRST_B < SECOND_B)
		swap(&stacks, BOTH, 1);

	// else if (last_value_bigger(STACK_B))
	// 	rotate(&stacks, B, 1);
	// else if (FIRST_B < SECOND_B)
	// 	swap(&stacks, B, 1);
	else if (last_value_bigger(STACK_B))
		reverse_rotate(&stacks, B, 1);

	else if (FIRST_A > SECOND_A)
		swap(&stacks, A, 1);
	else if (!last_value_bigger(STACK_A))
		reverse_rotate(&stacks, A, 1);
	// else if (!last_value_bigger(STACK_A))
	// 	rotate(&stacks, A, 1);

	else
		reverse_rotate(&stacks, A, 1);

	print_stacks(stacks); 
	if (stack_in_order(stacks))
		return ;
	sort_stack(stacks);
}

// void	sort_stack(t_stacks *stacks)
// {
// 	if (a_in_order(STACK_A))
// 	{
// 		push_all_to_a(stacks);
// 		return ;
// 	}
// 	else if (smallest_in_stack(STACK_A, FIRST_NODE))
// 		push(&stacks, B, 1);
// 	else if (smallest_closer_to_top(STACK_A, stacks->stack_size))
// 		rotate(&stacks, A, 1);
// 	else
// 		reverse_rotate(&stacks, A, 1);
// 	if (stack_in_order(stacks))
// 		return ;
// 	sort_stack(stacks);
// }

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
	// print_stacks(stacks);
	sort_stack(stacks);
	// print_stacks(stacks);
	// if (stack_in_order(stacks)) // TEMP
		// ft_printf("OK\n"); //TEMP
}