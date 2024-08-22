/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:33:06 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/22 16:57:06 by eedwards         ###   ########.fr       */
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

//returns a color based on whether the xx and yy given are part of the mandelbrot
//or Julia sets or not
int	which_color(t_fractal *fractal, double xx, double yy)
{
	int		iterations;
	
	if (!(ft_strncmp(fractal->title, "mandelbrot", 10)))
		iterations = ft_mandelbrot_check(xx, yy);
	else 
		iterations = ft_julia_check(xx, yy, fractal);
	return (fractal->color_array[iterations%100]);
	//add more colors, can add to header
}


//sets the values for the real and imaginary parts of the complex numbers
void	ft_set_compl_values(double real, double imaginary, t_complex *cz)
{
	cz->real = real;
	cz->imaginary = imaginary;
}

//checks whether an xx and yy are part of the mandelbrot set
//calculated by iterating formula: z = z^2 + c
// c real = xx / imaginary = yy
// z starts as 0
//If it diverges (absolute value of z is more than 2) within the iteration limit 
//(1000) then it is not part of the set 
int	ft_mandelbrot_check(double xx, double yy)
{
	t_complex	c;
	t_complex	z;
	int			iteration;

	ft_set_compl_values(xx, yy, &c);
	ft_set_compl_values(0, 0, &z);
	iteration = -1;
	while (++iteration < 1000 && absolute_complex(z) <= 2)
	{
		
	}
		z = sum_complex(squared_complex(z), c);
	return (iteration);
}

//checks whether an xx and yy are part of the Julia set
//calculated by iterating formula: z = z^2 + c
// c real and imaginary values set to arguements given in av
// z real = xx / imaginary = yy
//If it diverges (absolute value of z is more than 2) within the iteration limit 
//(1000) then it is not part of the set 
int	ft_julia_check(double xx, double yy, t_fractal *fractal)
{
	t_complex	c;
	t_complex	z;
	int			iteration;

	ft_set_compl_values(fractal->jul_arg1, fractal->jul_arg2, &c);
	ft_set_compl_values(xx, yy, &z);
	iteration = -1;
	while (++iteration < 1000 && absolute_complex(z) <= 2)
		z = sum_complex(squared_complex(z), c);
	return (iteration);
}


