/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:09:19 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/20 15:52:10 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	int	esc;

	esc = 65307;
	//ft_printf("keycode is: %i", keycode);
	if (keycode == esc)
		ft_close(fractal);
	if (keycode >= 65361 && keycode <= 65364)
		arrow_keys_hook(keycode, fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	t_complex	range;
	t_complex	center;
	
	range.real = fractal->x_max - fractal->x_min;
	range.imaginary = fractal->y_max - fractal->y_min;
	center.real = x;
	center.imaginary = y;
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
	fractal->x_min = center.real - range.real / 2;
	fractal->x_max = center.real + range.real / 2;
	fractal->y_min = center.imaginary - range.real / 2;
	fractal->y_max = center.imaginary + range.real / 2;
	parse_pixels(fractal);
	return (0);
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
		fractal->y_max -= offset;
		fractal->y_min -= offset;
	}
	if (keycode == 65363)//right
	{
		fractal->x_max += offset;
		fractal->x_min += offset;
	}
	if (keycode == 65364)//down
	{
		fractal->y_max += offset;
		fractal->y_min += offset;
	}
	parse_pixels(fractal);
	return (0);
}
