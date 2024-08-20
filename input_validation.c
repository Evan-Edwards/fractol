/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:03:42 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/20 12:23:53 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//checks that the inputs are correct
//av[1] should be either "mandelbrot" or "julia"
//av[2] and av[3] are 2 numbers if av[1] is "julia"
int	input_check(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		return (1);
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		if (check_julia_input(av[2]) && check_julia_input(av[3]))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

//checks if the string given is a valid input, can have 1 plus or
//minus and the other characters must be numbers
int	check_julia_input(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] == '-' || arg[i] == '+') && ft_isdigit(arg[i + 1]) == 1)
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}