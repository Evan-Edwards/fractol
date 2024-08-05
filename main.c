/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:45:38 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/05 15:58:35 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;

	/* if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
		//do program
	else
	{
		//print error message: "If no parameter is provided, or if the parameter is invalid, the program displays
//a list of available parameters and exits properly"
	} */

	mlx = mlx_init;
	if (!mlx)
		return (1);
	//graphical stuff
	//clean up display struct and xvar struct
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	mlx_loop(mlx);
	/* mlx_destroy_display(mlx);
	free(mlx);
	return (0); */
	
}

//Julia and Mandelbrot
//Infinite zoom
//able to take command line args to descide which fractal render
//take command line args to shape Julia
//Esc closes
//Clicking x on window closes the process