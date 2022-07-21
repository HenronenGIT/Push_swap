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

// void	check_input(int argc, char **arguments)
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
		// node_add_back(&(*stack_a), node);
		node_add_back(&(*stacks)->stack_a, node);
		i += 1;
	}
}

void	check_stack_order(t_stacks *stacks)
{
	t_stack	*node;

	if (stacks->stack_b != NULL)
		panic("KO");
	node = stacks->stack_a;
	while (node->next)
	{
		if (node->value < node->next->value)
			node = node->next;
		else
			panic("KO");
	}
	ft_putstr("OK");
}

int	main(int argc, char **argv)
{
	t_stacks		*stacks; 
	// t_instruction	*instructions;
	t_list			*instructions;
	int				*valid_numbers;
	int				array_len;
	// char	**instructions;

	if (argc < 2)
		return (1);
	array_len = argc - 1;
	valid_numbers = check_input(argc, argv);
	create_stacks(valid_numbers, array_len, &stacks);
	read_instructions(&instructions);
	// execute_instructions(&stacks);
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
