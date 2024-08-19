/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utitls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:29:14 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/19 12:37:21 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_hook(fractal->win, 17, 0, ft_close, fractal);
	//data_init//TODO

}

//after we go through every pixel then we push the img
void	pixel_put_image(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img_addr + (y * fractal->line_length + x * (fractal->bbp / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_fractal *fractal)
{
	int	esc;

	esc = 65307;
	ft_printf("keycode is: %i", keycode);
	if (keycode == esc)
		ft_close(fractal);
	return (0);
}

//destroys display and frees data used
int	ft_close(t_fractal *vars)
{
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
	exit (0);
}