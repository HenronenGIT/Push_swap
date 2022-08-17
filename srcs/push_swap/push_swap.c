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

int	*check_input(char **arguments)
{
	int		*valid_numbers;
	long	argument;
	int		i;

	i = 0;
	valid_numbers = (int *)malloc(sizeof(int) * (ft_count_pointers(arguments)));
	while (arguments[i])
	{
		if (!ft_isnumber(arguments[i]))
			panic("Error\n");
		argument = ft_atol(arguments[i]);
		if (argument > INT_MAX || argument < INT_MIN)
			panic("Error\n");
		if (ft_nbr_in_array((int)argument, valid_numbers, i))
			panic("Error\n");
		valid_numbers[i] = (int)argument;
		i += 1;
	}
	// ft_memdel((void *)&valid_numbers);
	return (valid_numbers);
}

char	**explode_arguments(int argc, char **argv)
{
	if (argc >= 2 && ft_isnumber(argv[0]))
		return (argv);
	return (ft_strsplit(argv[0], ' '));
}

int	main(int argc, char **argv)
{
	t_stacks		*stacks; 
	t_chunks		*chunks; 
	int				*valid_numbers;
	int				array_len;

	stacks = NULL;
	argv++;
	if (argc < 2)
		exit(1);
	argv = explode_arguments(argc, argv); // Might cause memory leak?
	valid_numbers = check_input(argv);
	create_stacks(valid_numbers, ft_count_pointers(argv), &stacks);
	chunks = create_chunks(stacks);
	sort_stack(stacks, chunks);
	// print_stacks(stacks);

	// if (stack_in_order(stacks)) // temp
		// printf("OK\n"); //temp
	// else
		// printf("KO\n"); //temp

	// if (stack_in_order(stacks))
	// {
		// ft_printf("0\n");
		// return (0); // Free all
	// }
}