/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:09:26 by hmaronen          #+#    #+#             */
/*   Updated: 2022/07/14 20:09:27 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(char *string)
{
	while (*string)
	{
		if (ft_isdigit(*string))
			string++;
		else
			return (0);
	}
	return (1);
}

int	wrong_input(char **arguments)
{
	int	i;

	i = 1;
	while (arguments[i])
	{
		if (ft_isnumber(arguments[i]))
			i += 1; 
		else
			return (1);
	}
	return (0);
}

void	panic()
{
	printf("Error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	if (wrong_input(argv))
		panic();
	return (0);
}