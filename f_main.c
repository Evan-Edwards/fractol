/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:45:38 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/28 15:54:11 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//1) checks that inputs are correct
//2)initiates mlx, mlx_window, mlx_image, and hooks
//3)uses parse_pixels to initiate image
//4)loops, image in window refreshed whenever hook used
int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (input_check(ac, av) == 0)
	{
		ft_putstr_fd("Input invalid. Examples of valid input:\n", 2);
		ft_putstr_fd("./fractol mandelbrot\n", 2);
		ft_putstr_fd("./fractol burning\n", 2);
		ft_putstr_fd("./fractol julia <num 1> <num 2>", 2);
		return (1);
	}
	fractal_mlx_init(&fractal);
	fractal_values_init(&fractal, av);
	parse_pixels(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
