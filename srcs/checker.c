/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:09:26 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/14 20:09:27 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	panic(char *error_message)
{
	ft_puterror(error_message);
	exit(0);
}

void	check_stack_order(t_stacks *stacks)
{
	t_stack	*node;

	if (stacks->stack_b != NULL)
		panic("KO\n");
	node = stacks->stack_a;
	while (node->next)
	{
		if (node->value < node->next->value)
			node = node->next;
		else
			panic("KO\n");
	}
	ft_putstr("OK\n");
}

int	main(int argc, char **argv)
{
	t_stacks		*stacks; 
	t_instruction	*instructions;
	int				*valid_numbers;
	int				array_len;

	instructions = NULL;
	// stacks = NULL;
	if (argc < 2)
		return (1);
	array_len = argc - 1;
	valid_numbers = check_input(argc, argv);
	create_stacks(valid_numbers, array_len, &stacks);
	read_instructions(&instructions);
	execute_instructions(instructions, &stacks);
	print_stacks(stacks); // TEMP
	check_stack_order(stacks);

	// free(valid_numbers);
	// while (stack_a)
	// {
	// 	free(stack_a);
	// 	stack_a = stack_a->next;
	// }
	// free(stack_b);
	return (0);
}
