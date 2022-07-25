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

t_stack	*fetch_last_node(t_stack *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

t_stacks	*quick_short(t_stacks *stacks)
{
	t_stack	*pivot;
	t_stack	*stack_a;
	t_stack	*iterator;

	iterator = NULL;
	pivot = NULL;
	stack_a = NULL;

	stack_a = stacks->stack_a;
	pivot = fetch_last_node(stacks->stack_a);
	while (stack_a)
	{
		if (iterator && stack_a->value <= pivot->value)
			
		else
			iterator = stack_a;
		stack_a = stack_a->next;
	}
	// printf("%d\n", pivot->value);
	return (stacks);
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
	
	stacks = quick_short(stacks);
	
	print_stacks(stacks);
}