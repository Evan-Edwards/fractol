/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:03:42 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/12 11:57:49 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//checks that the inputs are correct
//av[1] should be either "mandelbrot" or "julia"
//av[2] and av[3] are 2 numbers if av[1] is "julia"
int	input_check(int ac, char **av)
{
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		return (1);
	else if (ac == 2 && !ft_strcmp(av[1], "burning"))
		return (1);
	else if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		if (check_julia_input(av[2]) && check_julia_input(av[3]))
			return (1);
	}
	return (0);
}

//checks if the string given is a valid input, can have 1 plus or
//minus and the other characters must be numbers
//makes sure there is max 1 decimal point
int	check_julia_input(char *arg)
{
	int	i;
	int	dec;
	int	has_digit;

	i = 0;
	dec = 0;
	has_digit = 0;
	if ((arg[i] == '-' || arg[i] == '+') && arg[i + 1])
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]))
			has_digit = 1;
		else if (arg[i] == '.' && dec == 0)
			dec = 1;
		else
			return (0);
		i++;
	}
	return (has_digit == 1);
}
