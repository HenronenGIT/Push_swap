/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:14:00 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/22 09:14:02 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_input(int argc, char **arguments)
{
	int		*valid_numbers;
	int		array_size;
	long	argument;
	int		i;

	array_size = argc - 1;
	i = 0;
	if (argc < 2)
		panic("Error\n");
	arguments++;
	valid_numbers = (int *)malloc(sizeof(int) * (array_size));
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

// t_stack	*create_stacks(int *ints, int arr_len, t_stack **stack_a, t_stack **stack_b)
void	create_stacks(int *ints, int arr_len, t_stacks **stacks)
{
	t_stack	*node;
	int		i;

	i = 0;
	(*stacks) = (t_stacks *)malloc(sizeof(t_stacks));
	(*stacks)->stack_a = create_node(ints[i++]);
	while (i < arr_len)
	{
		node = create_node(ints[i]);
		node_add_back(&(*stacks)->stack_a, node);
		i += 1;
	}
	(*stacks)->stack_b = NULL;
}
