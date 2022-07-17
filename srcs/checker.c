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

// t_stack	*create_stacks(int *ints, int arr_len, t_stack **stack_a, t_stack **stack_b)
void	create_stacks(int *ints, int arr_len, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		i;

	i = 0;
	*stack_a = create_node(ints[i++]);
	while (i < arr_len)
	{
		node = create_node(ints[i]);
		node_add_back(&(*stack_a), node);
		i += 1;
	}
	// *stack_b = create_node(0);
	// return (stack);
}

int	check_stack_order(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node->next)
	{
		if (node->value < node->next->value)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

void	read_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;
	// static	t_operation	*jump_table[3] = {
	// 	swap,
	// 	rotate,
	// 	reverse_rotate
	// };
	
	// while (ft_get_next_line(1, &instruction)) // better way to clean huge if tree?
	// {
	// 	t_operation[]
	// 	print_stack(stack_a);

	while (ft_get_next_line(1, &instruction)) // better way to clean huge if tree?
	{
		if (!ft_strcmp(instruction, "sa"))
			swap(stack_a);
		else if (!ft_strcmp(instruction, "sb"))
			swap(stack_b);
		else if (!ft_strcmp(instruction, "ss"))
		{
			swap(stack_a);
			swap(stack_b);
		}
		else if (!ft_strcmp(instruction, "pa"))
			push(stack_a, stack_b);
		else if (!ft_strcmp(instruction, "pb"))
			push(stack_b, stack_a);
		else if (!ft_strcmp(instruction, "ra"))
			rotate(stack_a);
		else if (!ft_strcmp(instruction, "rb"))
			rotate(stack_b);
		else if (!ft_strcmp(instruction, "rr"))
		{
			rotate(stack_a);
			rotate(stack_b);
		}
		else if (!ft_strcmp(instruction, "rra"))
			reverse_rotate(stack_a);
		else if (!ft_strcmp(instruction, "rrb"))
			reverse_rotate(stack_b);
		else if (!ft_strcmp(instruction, "rrr"))
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
		}
		else
			exit(1); // Free everything
		print_stacks(*stack_a, *stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b; 
	int		*valid_numbers;
	int		array_len;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	array_len = argc - 1;
	valid_numbers = check_input(argc, argv);
	create_stacks(valid_numbers, array_len, &stack_a, &stack_b);
	read_instructions(&stack_a, &stack_b);
	check_stack_order(stack_a);

	free(valid_numbers);
	while (stack_a)
	{
		free(stack_a);
		stack_a = stack_a->next;
	}
	free(stack_b);
	return (0);
}
