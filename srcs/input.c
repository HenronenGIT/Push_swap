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

char	**explode_arguments(int argc, char **argv)
{
	if (argc >= 2 && ft_isnumber(argv[0]))
		return (argv);
	return (ft_strsplit(argv[0], ' '));
}

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
	(*stacks)->template = NULL;
	(*stacks)->stack_size = arr_len;
	(*stacks)->template = ints;
	sort_int_tab((*stacks)->template, (*stacks)->stack_size);
	if (arr_len >= 500)
		(*stacks)->chunk_count = 11;
	else if (arr_len >= 100)
		(*stacks)->chunk_count = 5;

	(*stacks)->half_value = (*stacks)->template[arr_len / 2]; // mayby useless
	return ;
}


int	stack_in_order(t_stacks *stacks)
{
	t_stack	*node;

	if (stacks->stack_b != NULL)
		return (0);
		// panic("KO\n");
	node = stacks->stack_a;
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