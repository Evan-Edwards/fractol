/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:29:14 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/12 11:05:29 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//initializes mlx, mlx window, mlx image, and the mlx hooks
//also sets values of variables in fractal
void	fractal_mlx_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		ft_error(fractal);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->title);
	if (!fractal->win)
		ft_error(fractal);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		ft_error(fractal);
	fractal->img_addr = mlx_get_data_addr(fractal->img, &fractal->bbp,
			&fractal->line_len, &fractal->endian);
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_hook(fractal->win, 17, 0, ft_close, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
}

void	fractal_values_init(t_fractal *fractal, char **av)
{
	fractal->x_min = -2.0;
	fractal->x_max = 2.0;
	fractal->y_min = -2.0;
	fractal->y_max = 2.0;
	fractal->title = av[1];
	fractal->iterations = 100.0;
	if (!(strncmp(av[1], "julia", 5)))
	{
		fractal->type = JULIA;
		fractal->jul_arg1 = ft_atod(av[2]);
		fractal->jul_arg2 = ft_atod(av[3]);
	}
	else if (!(ft_strncmp(fractal->title, "burning", 7)))
		fractal->type = BURNING;
	else
		fractal->type = MANDELBROT;
	fractal->color_array = set_color_array();
}

//makes a color_array based on color values given in fractol.h
//allows for cycling through colors
int	*set_color_array(void)
{
	static int	array[11];

	array[0] = COLOR_BLACK;
	array[1] = COLOR_DARK_PURPLE;
	array[2] = COLOR_PURPLE;
	array[3] = COLOR_VIOLET;
	array[4] = COLOR_MAGENTA;
	array[5] = COLOR_HOT_PINK;
	array[6] = COLOR_PINK;
	array[7] = COLOR_LIGHT_PINK;
	array[8] = COLOR_NEON_PINK;
	array[9] = COLOR_PSYCHADELIC;
	array[10] = COLOR_ORANGE;
	return (array);
}

//puts colored pixels into the fractal->img
//color determined by int color and pixel by x and y
void	pixel_put_image(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img_addr + (y * fractal->line_len + x * (fractal->bbp / 8));
	*(unsigned int *)dst = color;
}
