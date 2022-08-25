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

static void	decide_algorithm(t_stacks *stacks, t_chunks	*chunks)
{
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
	return ;
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_chunks	*chunks;
	int			*valid_numbers;

	stacks = NULL;
	argv++;
	if (argc < 2)
		exit(1);
	argv = explode_arguments(argc, argv);
	valid_numbers = check_input(argv);
	free(valid_numbers);
	stacks = create_stacks(valid_numbers, ft_count_pointers(argv), stacks);
	if (is_stack_sorted(stacks))
		exit(0);
	chunks = create_chunks(stacks);
	decide_algorithm(stacks, chunks);
	exit (0);
}
