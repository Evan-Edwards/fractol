/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:33:06 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/19 13:31:10 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_pixels(t_fractal *fractal, char **av)
{
	double	x;
	double	xx;
	double	y;
	double	yy;
	
	y = -1; //same as above
	while (++y <= HEIGHT)
	{
		yy = scaleBetween(y, -2, 2, 0, HEIGHT);
		x = -1;
		while (++x <= WIDTH)
		{
			xx = scaleBetween(x, -2, 2, 0, WIDTH);
			pixel_put_image(fractal, x, y, which_color(fractal, av, xx, yy));
		} 
	}
}

//returns a color based on whether the xx and yy given are part of the mandelbrot
//or Julia sets or not
int	which_color(t_fractal *fractal, char **av, double xx, double yy)
{
	int 	color1;
	int		color2;
	
	color1 = 6561336;
	color2 = 15426616;
	if (!(ft_strncmp(av[1], "mandelbrot", 10)))
	{
		if (ft_mandelbrot_check(xx, yy) == 1)
			return (color1);
		else
			return (color2);
	}
	else 
	{
		if (ft_julia_check(xx, yy, av) == 1)
			return (color1);
		else
			return (color2);
	}
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
		z = sum_complex(squared_complex(z), c);
	return (iteration == 1000);
}

//checks whether an xx and yy are part of the Julia set
//calculated by iterating formula: z = z^2 + c
// c real and imaginary values set to arguements given in av
// z real = xx / imaginary = yy
//If it diverges (absolute value of z is more than 2) within the iteration limit 
//(1000) then it is not part of the set 
int	ft_julia_check(double xx, double yy, char **av)
{
	t_complex	c;
	t_complex	z;
	int			iteration;

	ft_set_compl_values(ft_atoi(av[2]), ft_atoi(av[3]), &c);
	ft_set_compl_values(xx, yy, &z);
	iteration = -1;
	while (++iteration < 1000 && absolute_complex(z) <= 2)
		z = sum_complex(squared_complex(z), c);
	return (iteration == 1000);
}


