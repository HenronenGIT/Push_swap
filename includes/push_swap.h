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

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_stacks;

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
}	t_stack;

// typedef struct s_instruction
// {
// 	struct s_instruction	*next;
// 	char					*operation;
// }	t_instruction;

// typedef enum e_instruction
// {
// 	sa,
// 	sb,
// 	ss,
// 	pa,
// 	pb,
// 	ra,
// 	rb,
// 	rr,
// 	rra,
// 	rrb,
// 	rrr
// }	t_instruction;

typedef	void	t_operation(t_stack **stack);
// typedef void	t_handler_func(t_flags *flag);

int		*check_input(int argc, char **arguments);
void	create_stacks(int *ints, int arr_len, t_stacks **stacks);

void	panic(char *error_message);
void	print_stacks(t_stacks *stacks); // printf inside

void	swap(t_stacks **stacks, int decider);
void	push(t_stacks **stacks, int decider);
void	rotate(t_stacks **stacks, int decider);
void	reverse_rotate(t_stacks **stacks, int decider);

t_stack	*create_node(int value);
void	node_add_back(t_stack **stack, t_stack *node);

// char	**read_instructions(t_instruction **instructions);
void	execute_instructions(t_stacks **stacks);

void	check_stack_order(t_stacks *stacks);


#endif