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

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_chunks	*chunks;
	int			*valid_numbers;

	argv++;
	if (argc < 2)
		exit(1);
	argv = explode_arguments(argc, argv);
	valid_numbers = check_input(argv);
	stacks = create_stacks(valid_numbers, ft_count_pointers(argv), stacks);
	if (is_stack_sorted(stacks))
		exit(0);
	chunks = create_chunks(stacks);
	if (stacks->stack_size == 3)
		sort_3_stack(stacks);
	else if (stacks->stack_size == 5)
	{	
		push(&stacks, B, 1);
		push(&stacks, B, 1);
		sort_3_stack(stacks);
		sort_5_stack(stacks);
	}
	else
		sort_big_stacks(stacks, chunks);
	exit (0);
}
