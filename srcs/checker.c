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

// void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{	
// 		printf("%d\n", stack->value);
// 		stack = stack->next;
// 	}
// }

void	panic(void)
{
	ft_puterror("Error\n");
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
		panic();
	arguments++;
	valid_numbers = (int *)malloc(sizeof(int) * (array_size));
	while (arguments[i])
	{
		if (!ft_isnumber(arguments[i]))
			panic();
		argument = ft_atol(arguments[i]);
		if (argument > INT_MAX || argument < INT_MIN)
			panic();
		if (ft_nbr_in_array((int)argument, valid_numbers, i))
			panic();
		valid_numbers[i] = (int)argument;
		i += 1;
	}
	// ft_memdel((void *)&valid_numbers);
	return (valid_numbers);
}

// char	*read_instructions(t_stack *stack)
// {
// 	char	*instruction;

// 	stacic	jump_table
// 	while (ft_get_next_line(1, &instruction))
// 	{
		
// 	}
// }

t_stack	*create_stack(int *integers, int array_size)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	i = 0;
	stack = create_node(integers[i++]);
	while (i < array_size)
	{
		node = create_node(integers[i]);
		node_add_back(&stack, node);
		i += 1;
	}
	return (stack);
}

int	check_stack_order(t_stack *stack)
{
	t_stack	*node;
	int		temp;

	node = stack;
	temp = 0;
	while (node->next)
	{
		
		if (node->value < node->next->value)
			node = node->next;
		else
		{
			return (0);
			//temp = node->value;
			//node->value = node->next->value;
			//node->next->value = temp;
			//node = stack;
		}
	}
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	t_stack *stack_a;
// 	int		*valid_numbers;
// 	int		array_size;

// 	stack_a = NULL;
// 	array_size = argc - 1;
// 	valid_numbers = check_input(argc, argv);
// 	stack_a = create_stack(valid_numbers, array_size);
// 	// read_instructions(stack);
// 	// check_stack_order(stack_a);
// 	// print_stack(stack_a);
// 	while (stack_a)
// 	{
// 		free(stack_a);
// 		stack_a = stack_a->next;
// 	}
// 	return (0);
// }
