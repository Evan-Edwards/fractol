/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:29:14 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/20 11:33:24 by eedwards         ###   ########.fr       */
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
	if (!fractal->win)
		ft_close(fractal);
	fractal->img_addr = mlx_get_data_addr(fractal->img, &fractal->bbp, 
										&fractal->line_length, &fractal->endian);
	mlx_key_hook(fractal->win, esc_key_hook, fractal);
	mlx_hook(fractal->win, 17, 0, ft_close, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
}

void	fractal_init_values(t_fractal *fractal, char **av)
{
	fractal->x_min = -2;
	fractal->x_max = 2;
	fractal->y_min = -2;
	fractal->y_max = 2;
	fractal->title = av[1];
	fractal->jul_arg1 = ft_atoi(av[2]);
	fractal->jul_arg2 = ft_atoi(av[3]);
	
}

//after we go through every pixel then we push the img
void	pixel_put_image(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img_addr + (y * fractal->line_length + x * (fractal->bbp / 8));
	*(unsigned int*)dst = color;
}

int	esc_key_hook(int keycode, t_fractal *fractal)
{
	int	esc;

	esc = 65307;
	ft_printf("keycode is: %i", keycode);
	if (keycode == esc)
		ft_close(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	t_complex	range;
	t_complex	center;
	
	range.real = fractal->x_max - fractal->x_min;
	range.imaginary = fractal->y_max - fractal->y_min;
	if (button == 4)//scroll up
	{
		range.real *= 0.9;
		range.imaginary *= 0.9;
	}
	if (button == 5)//scroll down
	{
		range.real *= 1.1;
		range.imaginary *= 1.1;
	}
	
}

int	arrow_keys_hook(int	keycode, t_fractal *fractal)
{
	double	offset;

	offset = (fractal->x_max - fractal->x_min) / 10;
	if (keycode == 65361)//left
	{
		fractal->x_max -= offset;
		fractal->x_min -= offset;
	}
	if (keycode == 65362)//up
	{
		fractal->y_max += offset;
		fractal->y_min += offset;
	}
	if (keycode == 65363)//right
	{
		fractal->x_max += offset;
		fractal->x_min += offset;
	}
	if (keycode == 65364)//down
	{
		fractal->y_max -= offset;
		fractal->y_min -= offset;
	}
	parse_pixels(fractal);
}

int	

//destroys display and frees data used
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

void	malloc_error(void)
{
	ft_putstr_fd(MALLOC_ERR_MESSAGE, 2);
	exit (0);
	//is 0 the correct exit code?
}