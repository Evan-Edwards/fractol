/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:45:38 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/14 12:44:42 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_close(t_vars *vars)
{
	mlx_destroy_display(vars->mlx);
	free (vars->mlx); //neccessary to free?
	exit (0);
}

int	key_hook(int keycode, t_vars *vars) //does it need to be a t_vars *?
{
	ft_printf("keycode is: %i", keycode);
	if (keycode == 65307)
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

void	parse_pixels(t_img *img, char **av)
{
	int		x;
	int		y;
	int 	color;
	char	*temp;
	
	//go through every pixel, go through all the x values in a line
	//then increase y, x starts at 0 until it reaches the last pixel
	//then push the image
	//have to also make it into a grid
	//start over?
	temp = img->addr;
	while (img->addr != NULL)
	{
		y = (temp - img->addr) / img->line_length;
		x = (temp - img->addr) % img->line_length / (img->bbp / 8);
		if (ft_strncmp(av[1], "mandelbrot", 10))
		{
			if (ft_mandelbrot_check(x, y) == 1)
				pixel_put_image(img, x, y, color) ;// change color
			else
				pixel_put_image(img, x, y, color);// different color
		}
		else 
		{
			if (ft_julia_check(x, y, av) == 1)
				pixel_put_image(img, x, y, color); // change color
			else
				pixel_put_image(img, x, y, color);// different color
		}
	}
}


int	main(int ac, char **av)
{
	t_vars	vars;
	t_img	img;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
		ft_putstr("Input valid");
		//do program
	else
	{
		ft_putstr_fd("Please provide valid parameter, for example: ", 1); //TODO
	} 
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	//graphical stuff
	//clean up display struct and xvar struct
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World!");
	if (!vars.win)
		return (1);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bbp, &img.line_length, &img.endian);
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