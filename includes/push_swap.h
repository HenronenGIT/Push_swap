/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:41:46 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/13 14:41:47 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> //TEMP

# define A 0
# define B 1
# define BOTH 2

# define FIRST_A stacks->stack_a->value
# define FIRST_B stacks->stack_b->value
# define SECOND_A stacks->stack_a->next->value
# define SECOND_B stacks->stack_b->next->value
# define HALF_VALUE stacks->half_value
# define STACK_A stacks->stack_a
# define STACK_B stacks->stack_b

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				*sorted_stack;
	int				stack_size;
	int				chunk_count;
}	t_stacks;

typedef struct s_chunks
{
	int				*array;
	int				array_size;
	struct s_chunks	*next;
}	t_chunks;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*back;
	int				value;
}	t_stack;

typedef struct s_instruction
{
	char					*operation;
	// enum					operation;
	struct s_instruction	*next;
}	t_instruction;

char		**explode_arguments(int argc, char **argv);
int			*check_input(char **arguments);
t_stacks	*create_stacks(int *ints, int arr_len, t_stacks *stacks);
void		read_instructions(t_instruction **instructions);
void		execute_instructions(t_instruction *instructions, t_stacks **stacks);
int			stack_in_order(t_stacks *stacks);

t_chunks		*create_chunks(t_stacks *stacks);
static t_chunks *create_chunk_list(int chunk_count);
static int		allocate_chunk_arrays(t_chunks *chunk_list, t_stacks *stacks);
static void		fill_chunk(t_chunks *chunk, int chunk_size, int *sorted_stack);

void		panic(char *error_message);
void		print_stacks(t_stacks *stacks);

void		swap(t_stacks **stacks, int decider, int output);
void		push(t_stacks **stacks, int decider, int output);
void		rotate(t_stacks **stacks, int decider, int output);
void		reverse_rotate(t_stacks **stacks, int decider, int output);

t_stack		*create_node(int value);
void		node_add_back(t_stack **stack, t_stack *node);
void		sort_stack(t_stacks *stacks, t_chunks *chunks);

#endif