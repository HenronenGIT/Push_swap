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
	while (temp->next != 0)
		temp = temp->next;
	temp->next = node;
	node->next = NULL;
}

// void	add_to_list(t_instruction **instructions)
void	add_to_list(char *instruction, t_instruction **instructions)
{
	t_instruction	*node;

	if (!(*instructions))
	{
		(*instructions) = (t_instruction *)malloc(sizeof(t_instruction));
		(*instructions)->operation = ft_strdup(instruction);
		(*instructions)->next = NULL;
	}
	else
	{
		node = (t_instruction *)malloc(sizeof(t_instruction));
		node->operation = ft_strdup(instruction);
		node->next = NULL;
		instruction_addback(instructions, node);
		free(node);	
	}
}

void	read_instructions(t_instruction **instructions)
{
	// char *instruction;
	// instruction = NULL;

	/* Temp */
	char	*instruction;

	instruction = ft_strdup("rra");
	int i;

	i = 0;
	// while (ft_get_next_line(1, &instruction)) // better way to clean huge if tree?
	while (i <= 2) // better way to clean huge if tree?
	{
		if (!ft_strcmp("sa", instruction) || !ft_strcmp("sb", instruction) ||
			!ft_strcmp("ss", instruction) || !ft_strcmp("pa", instruction) ||
			!ft_strcmp("pb", instruction) || !ft_strcmp("ra", instruction) ||
			!ft_strcmp("rb", instruction) || !ft_strcmp("rr", instruction) ||
			!ft_strcmp("rra", instruction) || !ft_strcmp("rrb", instruction) ||
			!ft_strcmp("rrr", instruction))
				add_to_list(instruction, instructions);
		else
			panic("Error\n");
		instruction = ft_strcpy(instruction, "pb");
		i++;
	}
}

void	execute_instructions(t_stacks **stacks)
{
	char	*instruction;
	// Jump table
	while (ft_get_next_line(1, &instruction)) // better way to clean huge if tree?
	{
		if (!ft_strcmp(instruction, "sa"))
			swap(stacks, A);
		else if (!ft_strcmp(instruction, "sb"))
			swap(stacks, B);
		else if (!ft_strcmp(instruction, "ss"))
			swap(stacks, BOTH);
		else if (!ft_strcmp(instruction, "pa"))
			push(stacks, A);
		else if (!ft_strcmp(instruction, "pb"))
			push(stacks, B);
		else if (!ft_strcmp(instruction, "ra"))
			rotate(stacks, A);
		else if (!ft_strcmp(instruction, "rb"))
			rotate(stacks, B);
		else if (!ft_strcmp(instruction, "rr"))
			rotate(stacks, BOTH);
		else if (!ft_strcmp(instruction, "rra"))
			reverse_rotate(stacks, A);
		else if (!ft_strcmp(instruction, "rrb"))
			reverse_rotate(stacks, B);
		else if (!ft_strcmp(instruction, "rrr"))
			reverse_rotate(stacks, BOTH);
		else
			panic("Error\n"); // Free everything
		print_stacks(*stacks);
	}
}