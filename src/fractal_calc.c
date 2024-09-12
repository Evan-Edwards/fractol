/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:33:06 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/12 10:43:16 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

//goes through each pixel of the image
//finds place of pixel in 2d graph, tests if that point is in the mandelbrot set
//or if it diverges within set iteration in the julia set
//sets color accordingly
void	parse_pixels(t_fractal *fractal)
{
	double	x;
	double	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			pixel_put_image(fractal, x, y, which_color(fractal, x, y));
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

//returns a color based on whether the xx and yy given are part of the 
//mandelbrot or Julia sets or not
int	which_color(t_fractal *fractal, double x, double y)
{
	int		iterations;
	double	xx;
	double	yy;
	double	x_scale;
	double	y_scale;

	x_scale = (fractal->x_max - fractal->x_min) / (WIDTH - 1);
	y_scale = (fractal->y_max - fractal->y_min) / (HEIGHT - 1);
	yy = fractal->y_max - y * y_scale;
	xx = fractal->x_min + x * x_scale;
	if (fractal->type == MANDELBROT)
		iterations = ft_mandelbrot_check(xx, yy, fractal);
	else if (fractal->type == BURNING)
		iterations = ft_burning_ship_check(xx, yy, fractal);
	else
		iterations = ft_julia_check(xx, yy, fractal);
	if (iterations == fractal->iterations)
		return (fractal->color_array[0]);
	else
		return (fractal->color_array[iterations % 11]);
}

//checks whether an xx and yy are part of the mandelbrot set
//calculated by iterating formula: z = z^2 + c
//squaring z = zr^2 - zi^2 + 2 * zr * zi
// c real = xx / imaginary = yy
// z starts as 0
//If it diverges (absolute value of z^2 is more than 4) within iteration limit
//(initially 100) then it is not part of the set 
//(absolute value of z)^2 = zr^2 + zi^2
int	ft_mandelbrot_check(double cr, double ci, t_fractal *fractal)
{
	double	zi;
	double	zr;
	double	zi2;
	double	zr2;
	int		iteration;

	zi = 0.0;
	zr = 0.0;
	iteration = 0;
	while (iteration < fractal->iterations)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4.0)
			break ;
		zi = 2.0 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		iteration++;
	}
	return (iteration);
}

//checks whether a given x and y are part of the Julia set
//calculated by iterating formula: z = z^2 + c
//squaring z = zr^2 - zi^2 + 2 * zr * zi
// c real and imaginary values set to arguements given in av
// z real = xx / imaginary = yy
//If it diverges (absolute value of z ^2 is more than 4) within the
//iteration limit (initially 100) then it is not part of the set
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
	while (iteration < fractal->iterations)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4)
			break ;
		zi = 2.0 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		iteration++;
	}
	return (iteration);
}

//checks whether an xx and yy are part of the burning_ship set
//calculated by iterating formula: z = abs(z^2) - c
//abs value of squaring z = zr^2 - zi^2 + 2 * zr * zi
// c real = xx / imaginary = yy
// z starts as 0
//If it diverges (absolute value of z^2 is more than 4) within the
//iteration limit (initially 100) then it is not part of the set 
//(absolute value of z)^2 = zr^2 + zi^2
int	ft_burning_ship_check(double cr, double ci, t_fractal *fractal)
{
	double	zr;
	double	zi;
	double	zi2;
	double	zr2;
	int		iteration;

	zr = 0;
	zi = 0;
	iteration = 0;
	while (iteration < fractal->iterations)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4)
			break ;
		zi = fabs(2 * zr * zi) - ci;
		zr = zr2 - zi2 - cr;
		iteration++;
	}
	return (iteration);
}
