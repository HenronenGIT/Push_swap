/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:54:28 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/19 16:54:28 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all_lists(t_stacks **stacks, t_chunks **chunks)
{
	t_stack		*next;
	t_chunks	*iterator;

	while ((*stacks)->stack_a)
	{
		next = (*stacks)->stack_a->next;
		free((*stacks)->stack_a);
		(*stacks)->stack_a = next;
	}
	while ((*stacks)->stack_b)
	{
		next = (*stacks)->stack_b->next;
		free((*stacks)->stack_b);
		(*stacks)->stack_b = next;
	}
	while ((*chunks))
	{
		iterator = (*chunks)->next;
		free((*chunks)->array);
		free((*chunks));
		(*chunks) = iterator;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_chunks	*chunks;
	int			*valid_numbers;

	argv++;
	if (argc < 2)
		exit(1);
	argv = explode_arguments(argc, argv); // Might cause memory leak?
	valid_numbers = check_input(argv);

	/* if statements for smaller algos */

	stacks = create_stacks(valid_numbers, ft_count_pointers(argv), stacks);

	/* Printed sorted tab */
		// ft_print_tab(stacks->sorted_stack, stacks->stack_size);
		// exit (0);
	/* Printed sorted tab */

	if (stack_in_order(stacks))
		exit(0);
	chunks = create_chunks(stacks);

	/* Print chunk arrays */
	// ft_print_tab(chunks->array, 20);
	// ft_putchar('\n');
	// ft_print_tab(chunks->next->array, chunks->array_size);
	// ft_putchar('\n');
	// ft_print_tab(chunks->next->next->next->next->array, chunks->array_size);
	// ft_putchar('\n');
	// exit (0);
	/* Print chunk arrays */

	// Jump table possible ?
	if (stacks->stack_size == 3)
		sort_3_stack(stacks);
	else if (stacks->stack_size == 5)
	{	
		push(&stacks, B, 1);
		push(&stacks, B, 1);
		sort_3_stack(stacks);
		sort_5_stack(stacks);
	}
	else
		sort_stack(stacks, chunks);
	free(valid_numbers);
	free_all_lists(&stacks, &chunks);
}