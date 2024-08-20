/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:45:38 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/20 10:54:03 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

 void	all_pixels_red(t_fractal *fractal)
{
	int	x;
	int	y;
	int	red;
	
	red = 16711680;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			pixel_put_image(fractal, x, y, red);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
} 

int	main(int ac, char **av)
{
	t_fractal	fractal;

	//need to check that julia inputs correct
	if (input_check(ac, av))
		{
			ft_putstr("Input valid\n");
			fractal_init(&fractal);
			//all_pixels_red(&fractal);
			parse_pixels(&fractal, av);
			mlx_loop(fractal.mlx);
			//push image
			//repeat
		}
		
	else
	{
		ft_putstr_fd(INVALID_ARGS_MESSAGE, 2);
		return (0); //TODO
	} 
	parse_pixels(&fractal, av);
	mlx_loop(fractal.mlx);
	return (0);
}

//checks if the string given is a valid input, can have 1 plus or
//minus and the other characters must be numbers
int	ft_check_valid(char *arg)
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

int	input_check(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		return (1);
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		if (ft_check_valid(av[2]) && ft_check_valid(av[3]))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

//Infinite zoom
//able to take command line args to descide which fractal render
//take command line args to shape Julia
//Esc closes
//Clicking x on window closes the process