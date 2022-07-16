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

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);

}

void	node_add_back(t_stack **stack, t_stack *node)
{
	t_stack	*temp;

	if (!*stack || !node)
		return ;
	temp = *stack;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = node;
	node->next = NULL;
}
