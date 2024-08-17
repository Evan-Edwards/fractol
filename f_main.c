/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:45:38 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/17 13:25:44 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//destroys display and frees data used
int	ft_close(t_fractal *vars)
{
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
	exit (0);
}

int	key_hook(int keycode, t_vars *vars) //does it need to be a t_vars *?
{
	int	esc;

	esc = 65307;
	ft_printf("keycode is: %i", keycode);
	if (keycode == esc)
		ft_close(vars);
	return (0);
}
//after we go through every pixel then we push the img
void	pixel_put_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bbp / 8));
	*(unsigned int*)dst = color;
}

void	ft_set_compl_values(double real, double imaginary, t_complex *cz)
{
	cz->real = real;
	cz->imaginary = imaginary;
	cz->absolute_2 = real * real + imaginary * imaginary;
}

int	ft_mandelbrot_check(int x, int y)
{
	t_complex	c;
	t_complex	z;
	double		z_real;
	double		z_imag;
	int			iteration;

	ft_set_compl_values(x, y, &c);
	ft_set_compl_values(0, 0, &z);
	//need to scale, should go from -2 to 2 for each axis. 
	iteration = 0;
	while (iteration < 1000 && z.absolute_2 <= 4)
	{
		z_real = z.real * z_real - z.imaginary * z.imaginary + c.real;
		z_imag = 2 * z.real * z.imaginary + c.imaginary;
		ft_set_compl_values(z_real, z_imag, &z);
		iteration++;
	}
	return (iteration == 1000);
}
int	ft_julia_check(int x, int y, char **av)
{
	t_complex	c;
	t_complex	z;
	int		z_real;
	int		z_imag;
	int	iteration;

	ft_set_compl_values(ft_atoi(av[2]), ft_atoi(av[3]), &c);
	ft_set_compl_values(x, y, &z);
	iteration = 0;
	while (iteration < 1000 && z.absolute_2 <= 4)
	{
		z_real = z.real * z_real - z.imaginary * z.imaginary + c.real;
		z_imag = 2 * z.real * z.imaginary + c.imaginary;
		ft_set_compl_values(z_real, z_imag, &z);
		iteration++;
	}
	return (iteration == 1000);
}


void	parse_pixels(t_img *img, char **av)
{
	int		x;
	int		y;
	int 	color;
	int		color2;
	
	//go through ever x and y and 
	//then push the image
	//have to also make it into a grid
	//start over?
	
	color = 6561336;
	color2 = 15426616;
	x = 0; //what about if max_x is even, should i put into ft_set_max_xy?
	y = 0; //same as above
	while (y < img->max_y)
	{
		while (x < img->max_x)
		{
			if (!(ft_strncmp(av[1], "mandelbrot", 10)))
			{
				if (ft_mandelbrot_check(x - img->max_x / 2, img->max_y / 2 - y) == 1)
				pixel_put_image(img, x, y, color);
				else
				pixel_put_image(img, x, y, color2);
			}
			else 
			{
				if (ft_julia_check(x - img->max_x / 2, img->max_y / 2 - y, av) == 1)
					pixel_put_image(img, x, y, color);
				else
					pixel_put_image(img, x, y, color2);
			}
			x++;
		}
		x = 0;
		y++; 
	}
}

void	ft_set_max_xy(t_img *img)
{
	char	*last_address;

	img->max_x = img->line_length / (img->bbp / 8);
	last_address = img->addr;
	while (last_address != NULL)
		last_address++;
	img->max_y = (last_address - img->addr) / img->line_length + 1;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error(); //TODO
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->title);
	if (!fractal->win)
		ft_close(fractal);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	//check
	fractal->img_addr = mlx_get_data_addr(fractal->img, &fractal->bbp, 
										&fractal->line_length, &fractal->endian);
	//events_init; //TODO
	//data_init//TODO

}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
		{
			ft_putstr("Input valid");
			fractal.title = av[1];
			
		}
		
	else
	{
		ft_putstr_fd("Input invalid. Valid inputs: mandelbot OR julia 1 3\n", 1);
		return (0); //TODO
	} 
	//clean up display struct and xvar struct
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bbp, &img.line_length, &img.endian);
	ft_set_max_xy(&img);
	parse_pixels(&img, av);
	mlx_pixel_put(vars.mlx, vars.win, 100, 100, 16777215);
	mlx_loop(vars.mlx);
	return (0);
}

//Julia and Mandelbrot
//Infinite zoom
//able to take command line args to descide which fractal render
//take command line args to shape Julia
//Esc closes
//Clicking x on window closes the process