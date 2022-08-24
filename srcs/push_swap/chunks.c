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

/*
	Allocates AND fills int arrays inside t_chunks structure.
*/
static void	allocate_chunk_arrays(t_chunks *chunk_list, t_stacks *stacks)
{
	t_chunks	*temp;
	int			chunk_size;
	int			last_array_len;

	temp = chunk_list;
	chunk_size = stacks->stack_size / stacks->chunk_count;
	last_array_len = chunk_size;
	last_array_len += (stacks->stack_size - (stacks->chunk_count * chunk_size));
	while (temp->next)
	{
		temp->array = (int *)malloc(sizeof(int) * chunk_size);
		if (!temp->array)
			exit(1);
		fill_chunk(temp, chunk_size, stacks->sorted_stack);
		temp = temp->next;
	}
	temp->array = (int *)malloc(sizeof(int) * last_array_len);
	if (!temp->array)
		exit(1);
	fill_chunk(temp, last_array_len, stacks->sorted_stack);
}

/*
	Allocates linked list based on t_chunks structure.
	Returns pointer to first node called "head".
*/
static t_chunks	*create_chunk_list(int chunk_count)
{
	t_chunks	*head;
	t_chunks	*node_pointer;
	t_chunks	*temp;
	int			i;

	i = 1;
	head = (t_chunks *)malloc(sizeof(t_chunks));
	if (!head)
		exit(1);
	head->next = NULL;
	head->array = NULL;
	node_pointer = head;
	while (++i <= chunk_count)
	{
		temp = (t_chunks *)malloc(sizeof(t_chunks));
		if (!temp)
			exit(1);
		temp->next = NULL;
		node_pointer->next = temp;
		node_pointer = node_pointer->next;
	}
	return (head);
}

/*
	Counts how many chunks there needs to be,
	so sorting works as efficiently as possible.
	Return: Linked list named as chunk_list.
*/
t_chunks	*create_chunks(t_stacks *stacks)
{
	t_chunks	*chunk_list;

	if (stacks->stack_size >= 500)
		stacks->chunk_count = 12;
	else if (stacks->stack_size >= 100)
		stacks->chunk_count = 5;
	else
		stacks->chunk_count = 1;
	chunk_list = create_chunk_list(stacks->chunk_count);
	if (!chunk_list)
		exit(1);
	allocate_chunk_arrays(chunk_list, stacks);
	return (chunk_list);
}
