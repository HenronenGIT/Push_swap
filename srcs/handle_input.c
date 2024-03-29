/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:59:48 by hmaronen          #+#    #+#             */
/*   Updated: 2022/08/23 11:59:49 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Split first index of 2D array named "argv".
	Space is a delimiter.
	Return 2D array.
*/
char	**explode_arguments(int argc, char **argv)
{
	char	**exploded_arguments;

	exploded_arguments = NULL;
	if (argc >= 2 && ft_isnumber(argv[0]))
		return (argv);
	exploded_arguments = ft_strsplit(argv[0], ' ');
	if (!exploded_arguments)
		exit(1);
	return (exploded_arguments);
}

/*
	Iterating through 2D array called "arguments". 
	If one of the elements is not valid go to panic() function 
	Else return all the valid integers in array called "valid_numbers."
*/
int	*check_input(char **arguments)
{
	int		*valid_numbers;
	long	argument;
	int		i;

	i = 0;
	valid_numbers = (int *)malloc(sizeof(int) * (ft_count_pointers(arguments)));
	if (!valid_numbers)
		exit(1);
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
	return (valid_numbers);
}

/*
	Allocating space for "stacks" structure.
	Allocating space for stacks->stack_a linked list.
	After every node allocation, function also fills every node with 1 integer.
	Return value: "stacks" structure.
*/
t_stacks	*create_stacks(int *ints, int array_len, t_stacks *stacks)
{
	t_stack	*node;
	int		i;

	i = 0;
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	stacks->stack_a = create_node(ints[i++]);
	if (!stacks->stack_a)
		exit(1);
	while (i < array_len)
	{
		node = create_node(ints[i]);
		if (!node)
			exit(1);
		node_add_back(&stacks->stack_a, node);
		i += 1;
	}
	stacks->stack_b = NULL;
	stacks->sorted_stack = NULL;
	stacks->stack_size = array_len;
	stacks->sorted_stack = ints;
	sort_int_tab(stacks->sorted_stack, stacks->stack_size);
	return (stacks);
}
