/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:16:31 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/15 16:16:31 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Allocates t_stack structure and
	initializes its variable "value" to that parameter what is received.
	Return value is allocated node.
*/
t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		exit(1);
	node->value = value;
	node->next = NULL;
	node->back = NULL;
	return (node);
}

/*
	Adds node to end of the list and inits it back pointer to previous node
*/
void	node_add_back(t_stack **stack, t_stack *node)
{
	t_stack	*temp;

	if (!*stack || !node)
		return ;
	temp = *stack;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = node;
	node->back = temp;
	node->next = NULL;
}

int	list_size(t_stack *stack)
{
	int	node_count;

	if (!stack)
		return (0);
	node_count = 1;
	while (stack->next)
	{
		node_count += 1;
		stack = stack->next;
	}
	return (node_count);
}

