/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:09:19 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/12 11:05:25 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//initiates all the keyhooks
//esc key exits;
//arrow keys move around
//c will cycle the colors
//+ and - keys on the numpad increase and decrease iterations
int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY)
		ft_close(fractal);
	else if (keycode >= LEFT_KEY && keycode <= DOWN_KEY)
		arrow_keys_hook(keycode, fractal);
	else if (keycode == C_KEY)
		cycle_colors(fractal);
	else if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		iteration_change(fractal, keycode);
	return (0);
}

//initializes the mouse hooks
//scroll up and scroll down zoom in and out and it does it centered on where
//the mouse is located in the window
int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	double	range_r;
	double	range_i;
	double	mpr;
	double	mpi;

	mpr = (f->x_max - f->x_min) * x / (WIDTH - 1) + f->x_min;
	mpi = (f->y_max - f->y_min) * (-y + HEIGHT - 1) / (HEIGHT + 1) + f->y_min;
	if (button == SCROLL_UP)
		f->zoom = 0.8;
	else if (button == SCROLL_DOWN)
		f->zoom = 1.2;
	else
		return (0);
	range_r = (f->x_max - f->x_min) * f->zoom;
	range_i = (f->y_max - f->y_min) * f->zoom;
	f->x_min = mpr - range_r / 2;
	f->x_max = mpr + range_r / 2;
	f->y_min = mpi - range_i / 2;
	f->y_max = mpi + range_i / 2;
	parse_pixels(f);
	return (0);
}

//increases or decreases iterations when + or - key is pressed
void	iteration_change(t_fractal *fractal, int keycode)
{
	if (keycode == PLUS_KEY)
		fractal->iterations += 10;
	else if (keycode == MINUS_KEY)
		fractal->iterations -= 10;
	parse_pixels(fractal);
}

//moves the center of the window up/down/left/right
int	arrow_keys_hook(int keycode, t_fractal *fractal)
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

//cycles colors using the color array created
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
