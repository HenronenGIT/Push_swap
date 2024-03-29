/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:44:22 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/19 09:44:25 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instruction_addback(t_operation **list, t_operation *node)
{
	t_operation	*temp;

	if (!*list || !node)
		return ;
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	node->next = NULL;
}

void	add_to_list(char *instruction, t_operation **instructions)
{
	t_operation	*node;

	if (!(*instructions))
	{
		(*instructions) = (t_operation *)malloc(sizeof(t_operation));
		if (!(*instructions))
			exit(1);
		(*instructions)->operation = ft_strdup(instruction);
		if (!(*instructions)->operation)
			exit(1);
		(*instructions)->next = NULL;
	}
	else
	{
		node = (t_operation *)malloc(sizeof(t_operation));
		if (!node)
			exit(1);
		node->operation = ft_strdup(instruction);
		if (!node->operation)
			exit(1);
		node->next = NULL;
		instruction_addback(instructions, node);
	}
}

static void	jump_table(t_stacks **stacks, int decider, int output, char *str)
{
	int							index;
	static char					*operation_arr[] = {"sa", "sb", "ss", "pa",
		"pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	static t_executt_style		*jump_table[11] = {
		swap,
		swap,
		swap,
		push,
		push,
		rotate,
		rotate,
		rotate,
		reverse_rotate,
		reverse_rotate,
		reverse_rotate
	};

	index = 0;
	while (ft_strcmp(str, operation_arr[index]))
		index += 1;
	jump_table[index](stacks, decider, output);
}

void	execute_instructions(t_operation *instructions, t_stacks **stacks)
{
	while (instructions)
	{
		if (!ft_strcmp(instructions->operation, "sa")
			|| !ft_strcmp(instructions->operation, "pa")
			|| !ft_strcmp(instructions->operation, "ra")
			|| !ft_strcmp(instructions->operation, "rra"))
			jump_table(stacks, A, 0, instructions->operation);
		else if (!ft_strcmp(instructions->operation, "sb")
			|| !ft_strcmp(instructions->operation, "pb")
			|| !ft_strcmp(instructions->operation, "rb")
			|| !ft_strcmp(instructions->operation, "rrb"))
			jump_table(stacks, B, 0, instructions->operation);
		else if (!ft_strcmp(instructions->operation, "ss")
			|| !ft_strcmp(instructions->operation, "rr")
			|| !ft_strcmp(instructions->operation, "rrr"))
			jump_table(stacks, BOTH, 0, instructions->operation);
		else
			panic("Error\n");
		instructions = instructions->next;
	}
}

t_operation	*read_instructions(t_operation *instructions)
{
	char	*instruction;

	instruction = NULL;
	while (ft_get_next_line(0, &instruction))
	{
		if (!ft_strcmp("sa", instruction) || !ft_strcmp("sb", instruction)
			|| !ft_strcmp("ss", instruction) || !ft_strcmp("pa", instruction)
			|| !ft_strcmp("pb", instruction) || !ft_strcmp("ra", instruction)
			|| !ft_strcmp("rb", instruction) || !ft_strcmp("rr", instruction)
			|| !ft_strcmp("rra", instruction) || !ft_strcmp("rrb", instruction)
			|| !ft_strcmp("rrr", instruction))
			add_to_list(instruction, &instructions);
		else
			panic("Error\n");
		free(instruction);
	}
	return (instructions);
}
