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
	
	print_stacks(stacks);
}