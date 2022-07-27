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
		// free(node);	
	}
}

void	read_instructions(t_instruction **instructions)
{
	char *instruction;

	// instruction = ft_strdup("pa"); // FOR TESTING COMMANDS
	// int i; // FOR TESTING COMMANDS

	// i = 0; // FOR TESTING COMMANDS
	// while (i < 1) // FOR TESTING COMMANDS
	instruction = NULL;
	while (ft_get_next_line(1, &instruction)) // better way to clean huge if tree?
	{
		if (!ft_strcmp("sa", instruction) || !ft_strcmp("sb", instruction) ||
			!ft_strcmp("ss", instruction) || !ft_strcmp("pa", instruction) ||
			!ft_strcmp("pb", instruction) || !ft_strcmp("ra", instruction) ||
			!ft_strcmp("rb", instruction) || !ft_strcmp("rr", instruction) ||
			!ft_strcmp("rra", instruction) || !ft_strcmp("rrb", instruction) ||
			!ft_strcmp("rrr", instruction))
				add_to_list(instruction, instructions);
		else
			panic("Error\n"); // FREE ALL
		free(instruction);
		// instruction = ft_strcpy(instruction, "pb"); // FOR TESTING COMMANDS
		// i++; FOR TESTING COMMANDS
	}
}

void	execute_instructions(t_instruction *instructions, t_stacks **stacks)
{
	while (instructions) // Jump table possible ???
	{
		if (!ft_strcmp(instructions->operation, "sa"))
			swap(stacks, A, 0);
			// swap(stacks, A);
		else if (!ft_strcmp(instructions->operation, "sb"))
			swap(stacks, B, 0);
			// swap(stacks, B);
		else if (!ft_strcmp(instructions->operation, "ss"))
			swap(stacks, BOTH, 0);
			// swap(stacks, BOTH);
		else if (!ft_strcmp(instructions->operation, "pa"))
			push(stacks, A, 0);
			// push(stacks, A);
		else if (!ft_strcmp(instructions->operation, "pb"))
			push(stacks, B, 0);
			// push(stacks, B);
		else if (!ft_strcmp(instructions->operation, "ra"))
			rotate(stacks, A, 0);
			// rotate(stacks, A);
		else if (!ft_strcmp(instructions->operation, "rb"))
			rotate(stacks, B, 0);
			// rotate(stacks, B);
		else if (!ft_strcmp(instructions->operation, "rr"))
			rotate(stacks, BOTH, 0);
			// rotate(stacks, BOTH);
		else if (!ft_strcmp(instructions->operation, "rra"))
			reverse_rotate(stacks, A, 0);
			// reverse_rotate(stacks, A);
		else if (!ft_strcmp(instructions->operation, "rrb"))
			reverse_rotate(stacks, B, 0);
			// reverse_rotate(stacks, B);
		else if (!ft_strcmp(instructions->operation, "rrr"))
			reverse_rotate(stacks, BOTH, 0);
			// reverse_rotate(stacks, BOTH);
		else
			panic("Error\n"); // Free everything
		instructions = instructions->next;
		// print_stacks(*stacks); // TEMP
	}
}