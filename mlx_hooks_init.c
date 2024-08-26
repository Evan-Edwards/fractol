/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:09:19 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/26 14:39:55 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_hook(int keycode, t_fractal *fractal)
{
    
	if (keycode == ESC_KEY)
        ft_close(fractal);
    else if (keycode >= LEFT_KEY && keycode <= DOWN_KEY)
        arrow_keys_hook(keycode, fractal);
    else if (keycode == C_KEY)
        cycle_colors(fractal);
	else if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		//TODO
    return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	double	range_r;
	double	range_i;
	double	mouse_pos_r;
	double	mouse_pos_i;
	
	mouse_pos_r = scaleBetween(x, fractal->x_min, fractal->x_max, 0, WIDTH - 1);
	mouse_pos_i = scaleBetween(-y, fractal->y_min, fractal->y_max, -HEIGHT + 1, 0);
	if (button == SCROLL_UP)
		fractal->zoom = 0.8;
	else if (button == SCROLL_DOWN)
		fractal->zoom = 1.2;
	else
		return (0);
	range_r = (fractal->x_max - fractal->x_min) * fractal->zoom;
	range_i = (fractal->y_max - fractal->y_min) * fractal->zoom;
	fractal->x_min = mouse_pos_r - range_r / 2;
	fractal->x_max = mouse_pos_r + range_r / 2;
	fractal->y_min = mouse_pos_i - range_i / 2;
	fractal->y_max = mouse_pos_i + range_i / 2;
	parse_pixels(fractal);
	return (0);
}

int	arrow_keys_hook(int	keycode, t_fractal *fractal)
{
	double	offset;

	offset = (fractal->x_max - fractal->x_min) / 10;
	if (keycode == LEFT_KEY)
	{
		fractal->x_max -= offset;
		fractal->x_min -= offset;
	}
	if (keycode == UP_KEY)
	{
		fractal->y_max += offset;
		fractal->y_min += offset;
	}
	if (keycode == RIGHT_KEY)
	{
		fractal->x_max += offset;
		fractal->x_min += offset;
	}
	if (keycode == DOWN_KEY)
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
