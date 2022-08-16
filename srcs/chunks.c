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

static t_chunks *create_chunk_list(int chunk_count)
{
	t_chunks	*head;
	t_chunks	*node_pointer;
	t_chunks	*temp;
	int			i;

	i = 1;
	head = (t_chunks *)malloc(sizeof(t_chunks));
	head->next = NULL;
	node_pointer = head;
	while (++i <= chunk_count) // mayby goes 1 over
	{
		temp = (t_chunks *)malloc(sizeof(t_chunks));
		if (!temp)
			return (NULL);
		temp->next = NULL;
		node_pointer->next = temp;
		node_pointer = node_pointer->next;
		// free(temp);
		// i++;
	}
	return (head);
}

void	fill_chunk(t_chunks *chunk, int chunk_size, int *sorted_stack)
{
	static int	last_position;
	int	i;
	int	j;

	i = 0;
	j = last_position; // Can cause problems on first run if last_position is not 0
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

static void	allocate_chunk_arrays(t_chunks *chunk_list, t_stacks *stacks)
{
	t_chunks	*temp;
	int			chunk_size;
	int			i;
	int			last_chunk_size;

	i = 0;
	chunk_size = stacks->stack_size / stacks->chunk_count + 0.6;
	last_chunk_size = chunk_size;
	last_chunk_size += (stacks->stack_size - (stacks->chunk_count * chunk_size));
	while (temp->next)
	{
		temp->array = (int *)malloc(sizeof(int) * chunk_size);
		fill_chunk(temp, chunk_size, stacks->sorted_stack);
		temp = temp->next;
		i += 1;
	}
	temp->array = (int *)malloc(sizeof(int) * last_chunk_size);
	fill_chunk(temp, last_chunk_size, stacks->sorted_stack);
	return ;
}

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
	allocate_chunk_arrays(chunk_list, stacks);
	return (chunk_list);
}