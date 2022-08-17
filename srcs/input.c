/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:14:00 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/22 09:14:02 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stacks(int *ints, int arr_len, t_stacks **stacks)
{
	t_stack	*node;
	int		i;

	i = 0;
	(*stacks) = (t_stacks *)malloc(sizeof(t_stacks));
	(*stacks)->stack_a = create_node(ints[i++]);
	while (i < arr_len)
	{
		node = create_node(ints[i]);
		node_add_back(&(*stacks)->stack_a, node);
		i += 1;
	}
	(*stacks)->stack_b = NULL;
	(*stacks)->sorted_stack = NULL;
	(*stacks)->stack_size = arr_len;
	(*stacks)->sorted_stack = ints;
	sort_int_tab((*stacks)->sorted_stack, (*stacks)->stack_size);
	return ;
}

int	stack_in_order(t_stacks *stacks)
{
	t_stack	*node;

	if (stacks->stack_b != NULL)
		return (0);
		// panic("KO\n");
	node = stacks->stack_a;
	while (node->next)
	{
		if (node->value < node->next->value)
			node = node->next;
		else
			return (0);
			// panic("KO\n");
	}
	return (1);
	// ft_putstr("OK\n");
}