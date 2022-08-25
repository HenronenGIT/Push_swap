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

# define A 0
# define B 1
# define BOTH 2
# define ROTATE 3
# define REVERSE_ROTATE 4
# define SWAP 4

# define FIRST_A stacks->stack_a->value
# define FIRST_B stacks->stack_b->value
# define SECOND_A stacks->stack_a->next->value
# define SECOND_B stacks->stack_b->next->value
# define STACK_A stacks->stack_a
# define STACK_B stacks->stack_b

typedef enum
{
	s,
	p,
	r,
	rr
}	e_operation;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				*sorted_stack;
	int				stack_size;
	int				chunk_count;
}	t_stacks;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*back;
	int				value;
}	t_stack;

typedef struct s_chunks
{
	int				*array;
	int				array_size;
	struct s_chunks	*next;
}	t_chunks;

typedef struct s_instruction
{
	char					*operation;
	struct s_instruction	*next;
}	t_instruction;

void		swap(t_stacks **stacks, int decider, int output);
void		push(t_stacks **stacks, int decider, int output);
void		rotate(t_stacks **stacks, int decider, int output);
void		reverse_rotate(t_stacks **stacks, int decider, int output);

t_instruction	*read_instructions(t_instruction *instructions);
void	execute_instructions(t_instruction *instructions, t_stacks **stacks);

char		**explode_arguments(int argc, char **argv);
int			*check_input(char **arguments);
t_stacks	*create_stacks(int *ints, int arr_len, t_stacks *stacks);

t_chunks	*create_chunks(t_stacks *stacks);
void		sort_3_stack(t_stacks *stacks);
void		sort_5_stack(t_stacks *stacks);
void		sort_big_stacks(t_stacks *stacks, t_chunks *chunks);

int		stack_in_ascending_order(t_stack *stack);
int		stack_in_descending_order(t_stack *stack);
int		biggest_in_stack(t_stack *stack, int value);
int		smallest_in_stack(t_stack *stack, int value);
int		smallest_closer_to_top(t_stack *stack, int stack_size);

void	move_value_to_top(int movable_index, t_stacks *stacks, int decider);
void	push_all_to_a(t_stacks *stacks);
void	rotate_many(int rotations, t_stacks **stacks, int stack, int operation);

t_stack	*create_node(int value);
void	node_add_back(t_stack **stack, t_stack *node);
int		list_size(t_stack *stack);

void	panic(char *error_message);
void	print_stacks(t_stacks *stacks);
int		is_stack_sorted(t_stacks *stacks);

int		fetch_smallest_index(t_stack *stack);
int		fetch_index_from_top(t_stack *stack_a, t_chunks *chunks);
int		fetch_index_from_bottom(t_stack *stack_a, t_chunks *chunks);
int		fetch_biggest_index(t_stack *stack);

void	add_to_list(char *instruction, t_instruction **instructions);

#endif