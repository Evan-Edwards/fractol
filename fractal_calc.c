/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:33:06 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/26 14:39:58 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_pixels(t_fractal *fractal)
{
	double	x;
	double	xx;
	double	y;
	double	yy;
	
	y = -1;
	while (++y < HEIGHT)
	{
		//does this need to be opposite?
		yy = scaleBetween(-y, fractal->y_min, fractal->y_max, -(HEIGHT - 1), 0);
		x = -1;
		while (++x < WIDTH)
		{
			xx = scaleBetween(x, fractal->x_min, fractal->x_max, 0, WIDTH - 1);
			pixel_put_image(fractal, x, y, which_color(fractal, xx, yy));
		} 
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

double	scaleBetween(double unscaled, double new_min, double new_max, 
										double old_min, double old_max)
{
	return((new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min);
}

//returns a color based on whether the xx and yy given are part of the mandelbrot
//or Julia sets or not
int	which_color(t_fractal *fractal, double xx, double yy)
{
	int		iterations;
	
	if (!(ft_strncmp(fractal->title, "mandelbrot", 10)))
		iterations = ft_mandelbrot_check(xx, yy);
	else 
		iterations = ft_julia_check(xx, yy, fractal);
	return (fractal->color_array[iterations % 11]);
	//add more colors, can add to header
}

//checks whether an xx and yy are part of the mandelbrot set
//calculated by iterating formula: z = z^2 + c
//squaring z = zr^2 - zi^2 + 2 * zr * zi
// c real = xx / imaginary = yy
// z starts as 0
//If it diverges (absolute value of z^2 is more than 4) within the iteration limit 
//(1000) then it is not part of the set 
//(absolute value of z)^2 = zr^2 + zi^2
int	ft_mandelbrot_check(double cr, double ci)
{
	double	zi;
	double	zr;
	double	zi2;
	double	zr2;
	int		iteration;

	zi = 0.0;
	zr = 0.0;
	iteration = 0;
	while (iteration < 1000)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4.0 )
			break;
		zr = zr2 - zi2 + cr;
		zi = 2.0 * zr * zi + ci;
		iteration++;
	}
	return (iteration);
}

//checks whether a given x and y are part of the Julia set
//calculated by iterating formula: z = z^2 + c
//squaring z = zr^2 - zi^2 + 2 * zr * zi
// c real and imaginary values set to arguements given in av
// z real = xx / imaginary = yy
//If it diverges (absolute value of z ^2 is more than 4) within the iteration limit 
//(1000) then it is not part of the set
//(absolute value of z)^2 = zr^2 + zi^2
int	ft_julia_check(double zr, double zi, t_fractal *fractal)
{
	double	cr;
	double	ci;
	double	zi2;
	double	zr2;
	int		iteration;

	cr = fractal->jul_arg1;
	ci = fractal->jul_arg2;
	iteration = 0;
	while (iteration < 1000)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4 )
			break;
		zr = zr2 - zi2 + cr;
		zi = 2.0 * zr * zi + ci;
		iteration++;
	}
	return (iteration);
}


