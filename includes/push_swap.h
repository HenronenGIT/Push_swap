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

// # include "libft.h"
# include <stdio.h> //TEMP

typedef struct s_stack
{
	long	value;
	struct s_stack	*next;
}	t_stack;

t_stack	*swap(t_stack *stack);
// t_stack	*push(t_stack *dest_stack, t_stack *source_stack);
void	push(t_stack **dest_stack, t_stack **source_stack);

#endif