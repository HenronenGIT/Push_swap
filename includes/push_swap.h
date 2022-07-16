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

/*
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
*/

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
}	t_stack;

// typedef	void	instruction()

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

void	swap(t_stack **stack);
void	push(t_stack **dest_stack, t_stack **source_stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

t_stack	*create_node(int value);
void	node_add_back(t_stack **stack, t_stack *node);

#endif