/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:29:14 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/27 12:55:01 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fractal, char **av)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error(fractal);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->title);
	if (!fractal->win)
		ft_close(fractal);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		ft_close(fractal);
	fractal->img_addr = mlx_get_data_addr(fractal->img, &fractal->bbp, 
										&fractal->line_length, &fractal->endian);
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_hook(fractal->win, 17, 0, ft_close, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	fractal->x_min = -2.0;
	fractal->x_max = 2.0;
	fractal->y_min = -2.0;
	fractal->y_max = 2.0;
	fractal->title = av[1];
	fractal->iterations = 100.0;
	if (!(strncmp(av[1], "julia", 5)))
	{
		fractal->jul_arg1 = ft_atod(av[2]);
		fractal->jul_arg2 = ft_atod(av[3]);
	}
	fractal->color_array = set_color_array();
}


int	*set_color_array(void)
{
		static int	array[11];

		array[0] = COLOR_BLACK;
		array[1] = COLOR_WHITE;
		array[2] = COLOR_RED;
		array[3] = COLOR_GREEN;
		array[4] = COLOR_BLUE;
		array[5] = COLOR_YELLOW;
		array[6] = COLOR_CYAN;
		array[7] = COLOR_MAGENTA;
		array[8] = COLOR_PSY_1;
		array[9] = COLOR_PSY_2;
		array[10] = COLOR_PSY_3;
		return (array);
}

//puts colored pixels into the fractal->img
//color determined by int color and pixel by x and y
void	pixel_put_image(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img_addr + (y * fractal->line_length + x * (fractal->bbp / 8));
	*(unsigned int*)dst = color;
}

//destroys image, window, and display and frees mlx
//then exits
int	ft_close(t_fractal *fractal)
{
	if (fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free (fractal->mlx);
	exit (0);
	//is 0 the correct exit code?
}

//gives an error message if malloc fails then exits
void	malloc_error(t_fractal *fractal)
{
	ft_putstr_fd(MALLOC_ERR_MESSAGE, 2);
	ft_close(fractal);
}