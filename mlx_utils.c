/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:29:14 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/20 15:44:16 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error();
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
	//ft_putstr("Fractal intiated\n");
}

//initializes the non-initialized variables in the fractal struct
void	fractal_init_values(t_fractal *fractal, char **av)
{
	fractal->x_min = -2;
	fractal->x_max = 2;
	fractal->y_min = -2;
	fractal->y_max = 2;
	fractal->title = av[1];
	if (!(strncmp(av[1], "julia", 5)))
	{
		fractal->jul_arg1 = ft_atod(av[2]);
		fractal->jul_arg2 = ft_atod(av[3]);
	}
	ft_putstr("check\n");
	printf("Arg 1: %f\n", fractal->jul_arg1);
	printf("Arg 2: %f\n", fractal->jul_arg2);
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
		mlx_destroy_image(fractal->mlx, fractal->img_addr);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free (fractal->mlx);
	exit (0);
	//is 0 the correct exit code?
}

//gives an error message if malloc fails then exits
void	malloc_error(void)
{
	ft_putstr_fd(MALLOC_ERR_MESSAGE, 2);
	exit (0);
	//is 0 the correct exit code?
}