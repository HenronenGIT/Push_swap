/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:43:24 by hmaronen          #+#    #+#             */
/*   Updated: 2022/08/09 14:43:25 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_chunk(t_chunks *chunk, int chunk_size, int *sorted_stack)
{
	int			i;
	int			j;
	static int	last_position;

	i = 0;
	j = last_position;
	chunk->array_size = chunk_size;
	while (i < chunk_size)
	{
		chunk->array[i] = sorted_stack[j];
		i++;
		j++;
	}
	last_position += i;
	return ;
}

static int	allocate_chunk_arrays(t_chunks *chunk_list, t_stacks *stacks)
{
	t_chunks	*temp;
	int			chunk_size;
	int			last_chunk_size;

	temp = chunk_list;
	chunk_size = stacks->stack_size / stacks->chunk_count;
	last_chunk_size = chunk_size;
	last_chunk_size += (stacks->stack_size - (stacks->chunk_count * chunk_size));
	while (temp->next)
	{
		temp->array = (int *)malloc(sizeof(int) * chunk_size);
		if (!temp->array)
			return (0); // change to exit
		fill_chunk(temp, chunk_size, stacks->sorted_stack);
		temp = temp->next;
	}
	temp->array = (int *)malloc(sizeof(int) * last_chunk_size);
	if (!temp->array)
		return (0); // change to exit
	fill_chunk(temp, last_chunk_size, stacks->sorted_stack);
	return (1); //mayby no need to return anything
}

static t_chunks *create_chunk_list(int chunk_count)
{
	t_chunks	*head;
	t_chunks	*node_pointer;
	t_chunks	*temp;
	int			i;

	i = 1;
	head = (t_chunks *)malloc(sizeof(t_chunks));
	if (!head)
		return (NULL);
	head->next = NULL;
	head->array = NULL;
	node_pointer = head;
	while (++i <= chunk_count) // mayby goes 1 over
	{
		temp = (t_chunks *)malloc(sizeof(t_chunks));
		if (!temp)
			return (NULL);
		temp->next = NULL;
		node_pointer->next = temp;
		node_pointer = node_pointer->next;
	}
	return (head);
}

/*
	Counts how many chunks there needs to be,
	so sorting works as efficiently as possible.
	Calls create_chunk_list() function which allocates t_chunks structure
	linked list.
	Calls allocate_chunk_arrays() functions which allocates t_chunks structure
	int array.
	Return: Linked list named as chunk_list.
*/
t_chunks	*create_chunks(t_stacks *stacks)
{
	t_chunks	*chunk_list;

	if (stacks->stack_size >= 500)
		stacks->chunk_count = 11;
	else if (stacks->stack_size >= 100)
		stacks->chunk_count = 5;
	else
		stacks->chunk_count = 1;	// temp
	chunk_list = create_chunk_list(stacks->chunk_count);
	if (!chunk_list)
		exit(1);
	if (!allocate_chunk_arrays(chunk_list, stacks))
		exit(1);
	return (chunk_list);
}