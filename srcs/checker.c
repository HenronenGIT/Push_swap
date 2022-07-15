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

void	panic(void)
{
	ft_puterror("Error\n");
	exit(0);
}

int	ft_isnumber(char *string)
{
	if (*string == '-')
		string++;
	while (*string)
	{
		if (ft_isdigit(*string))
			string++;
		else
			return (0);
	}
	return (1);
}

int	ft_in_array(int number, int *array, int array_size)
{
	int	i;

	i = 0;
	while (i <= array_size)
	{
		if (number == array[i])
			return (1);
		i += 1;
	}
	return (0);
}

// void	check_input(int argc, char **arguments)
int	*check_input(int argc, char **arguments)
{
	int		*valid_numbers;
	int		array_size;
	long	argument;
	int		i;

	array_size = argc - 1;
	i = 1;
	if (argc < 2)
		panic();
	valid_numbers = (int *)malloc(sizeof(int) * (array_size));
	while (arguments[i])
	{
		if (!ft_isnumber(arguments[i]))
			panic();
		argument = ft_atol(arguments[i]);
		if (argument > INT_MAX || argument < INT_MIN)
			panic();
		if (ft_in_array((int)argument, valid_numbers, array_size))
			panic();
		valid_numbers[i] = (int)argument;
		i += 1;
	}
	// ft_memdel((void *)&valid_numbers);
	return (valid_numbers);
}

int	main(int argc, char **argv)
{
	int	*valid_numbers;

	valid_numbers = check_input(argc, argv);
	
	return (0);
}
