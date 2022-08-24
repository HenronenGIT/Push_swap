/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:31:29 by hmaronen          #+#    #+#             */
/*   Updated: 2022/08/24 14:31:30 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	static char	*operations[3][4] = {
	{"sa", "pa", "ra", "rra"},
	{"sb", "pb", "rb", "rrb"},
	{"ss", "rr", "rrr"}
	};

	printf("%s\n", operations[A][0]);
	printf("%s\n", operations[B][0]);
}
