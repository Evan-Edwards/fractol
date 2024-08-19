/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:45:38 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/19 12:52:03 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
		{
			ft_putstr("Input valid");
			fractal.title = av[1];
			fractal_init(&fractal);
			//parse pixels
			//push image
			//repeat
		}
		
	else
	{
		ft_putstr_fd("Input invalid. Valid inputs: mandelbot OR julia 1 3\n", 1);
		return (0); //TODO
	} 
	parse_pixels(&fractal, av);
	mlx_loop(fractal.mlx);
	return (0);
}

//Infinite zoom
//able to take command line args to descide which fractal render
//take command line args to shape Julia
//Esc closes
//Clicking x on window closes the process