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

void	instruction_addback(t_instruction **list, t_instruction *node)
{
	t_instruction	*temp;

	if (!*list || !node)
		return ;
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	node->next = NULL;
}

void	add_to_list(char *instruction, t_instruction **instructions)
{
	t_instruction	*node;

	if (!(*instructions))
	{
		(*instructions) = (t_instruction *)malloc(sizeof(t_instruction));
		if (!(*instructions))
			exit(1);
		(*instructions)->operation = ft_strdup(instruction);
		if (!(*instructions)->operation)
			exit(1);
		(*instructions)->next = NULL;
	}
	else
	{
		node = (t_instruction *)malloc(sizeof(t_instruction));
		if (!node)
			exit(1);
		node->operation = ft_strdup(instruction);
		if (!node->operation)
			exit(1);
		node->next = NULL;
		instruction_addback(instructions, node);
	}
}

void	execute_instructions(t_instruction *instructions, t_stacks **stacks)
{
	while (instructions)
	{
		if (!ft_strcmp(instructions->operation, "sa"))
			swap(stacks, A, 0);
		else if (!ft_strcmp(instructions->operation, "sb"))
			swap(stacks, B, 0);
		else if (!ft_strcmp(instructions->operation, "ss"))
			swap(stacks, BOTH, 0);
		else if (!ft_strcmp(instructions->operation, "pa"))
			push(stacks, A, 0);
		else if (!ft_strcmp(instructions->operation, "pb"))
			push(stacks, B, 0);
		else if (!ft_strcmp(instructions->operation, "ra"))
			rotate(stacks, A, 0);
		else if (!ft_strcmp(instructions->operation, "rb"))
			rotate(stacks, B, 0);
		else if (!ft_strcmp(instructions->operation, "rr"))
			rotate(stacks, BOTH, 0);
		else if (!ft_strcmp(instructions->operation, "rra"))
			reverse_rotate(stacks, A, 0);
		else if (!ft_strcmp(instructions->operation, "rrb"))
			reverse_rotate(stacks, B, 0);
		else if (!ft_strcmp(instructions->operation, "rrr"))
			reverse_rotate(stacks, BOTH, 0);
		else
			panic("Error\n");
		instructions = instructions->next;
	}
}

t_instruction	*read_instructions(t_instruction *instructions)
{
	char	*instruction;

	instruction = NULL;
	while (ft_get_next_line(0, &instruction))
	{
		if (!ft_strcmp("sa", instruction) || !ft_strcmp("sb", instruction) ||
			!ft_strcmp("ss", instruction) || !ft_strcmp("pa", instruction) ||
			!ft_strcmp("pb", instruction) || !ft_strcmp("ra", instruction) ||
			!ft_strcmp("rb", instruction) || !ft_strcmp("rr", instruction) ||
			!ft_strcmp("rra", instruction) || !ft_strcmp("rrb", instruction) ||
			!ft_strcmp("rrr", instruction))
			add_to_list(instruction, &instructions);
		else
			panic("Error\n");
		free(instruction);
	}
	return (instructions);
}
