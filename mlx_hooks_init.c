/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:09:19 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/22 16:44:26 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	int	esc;
	int	c;

	esc = 65307;
	c = 99;
	//ft_printf("keycode is: %i", keycode);
	if (keycode == esc)
		ft_close(fractal);
	if (keycode >= 65361 && keycode <= 65364)
		arrow_keys_hook(keycode, fractal);
	if (keycode == c)
		cycle_colors(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	t_complex	range;
	t_complex	mouse_pos;
	
	
	mouse_pos.real = scaleBetween(x, fractal->x_min, fractal->x_max, 0, WIDTH - 1);
	mouse_pos.imaginary = scaleBetween(-y, fractal->y_min, fractal->y_max, -HEIGHT + 1, 0);
	if (button == 4)//scroll up
		fractal->zoom = 0.9;
	else if (button == 5)//scroll down
		fractal->zoom = 1.1;
	else
		return (0);
	range.real = (fractal->x_max - fractal->x_min) * fractal->zoom;
	range.imaginary = (fractal->y_max - fractal->y_min) * fractal->zoom;
	fractal->x_min = mouse_pos.real - range.real / 2;
	fractal->x_max = mouse_pos.real + range.real / 2;
	fractal->y_min = mouse_pos.imaginary - range.real / 2;
	fractal->y_max = mouse_pos.imaginary + range.real / 2;
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
	return (0);
}

void	cycle_colors(t_fractal *fractal)
{
	int	temp;
	int	i;

	i = -1;
	temp = fractal->color_array[0];
	while (++i < 10)
		fractal->color_array[i] = fractal->color_array[i + 1];
	fractal->color_array[10] = temp;
	parse_pixels(fractal);
}
