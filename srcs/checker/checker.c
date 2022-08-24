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

int	main(int argc, char **argv)
{
	t_stacks		*stacks;
	t_instruction	*instructions;
	int				*valid_numbers;

	stacks = NULL;
	instructions = NULL;
	argv++;
	if (argc < 2)
		exit(1);
	argv = explode_arguments(argc, argv);
	valid_numbers = check_input(argv);
	stacks = create_stacks(valid_numbers, ft_count_pointers(argv), stacks);
	instructions = read_instructions(instructions);
	execute_instructions(instructions, &stacks);
	if (is_stack_sorted(stacks))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(0);
}
