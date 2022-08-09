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
	int			i;

	i = 0;
	head = NULL;
	node_pointer = head;
	while (i <= chunk_count)
	{
		node_pointer = (t_chunks *)malloc(sizeof(t_chunks));
		if (!node_pointer)
			return (NULL);
		node_pointer->next = NULL;
		i++;
	}
	return (head);
}

t_chunks	*create_chunk_list(t_stacks *stacks)
{
	t_chunks *head;
	int		i;

	i = 0;
	head = create_chunk_list(stacks->chunk_count);
	return (head);
}