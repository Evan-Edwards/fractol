/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:09:19 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/30 11:54:19 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

//initiates all the keyhooks
//esc key exits;
//arrow keys move around
//c will cycle the colors
//+ and - keys on the numpad increase and decrease iterations
int key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY)
        ft_close(fractal);
	else if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		iteration_change(fractal, keycode);
    return (0);
}

//initializes the mouse hooks
//scroll up and scroll down zoom in and out
int	mouse_hook(int button, t_fractal *fractal)
{
	double	range_r;
	double	range_i;
	double	center_x;
	double	center_y;
	
	
	range_r = (fractal->x_max - fractal->x_min);
	range_i = (fractal->y_max - fractal->y_min);
	center_x = fractal->x_max - range_r / 2;
	center_y = fractal->y_max - range_i	/ 2;
	if (button == SCROLL_UP)
		fractal->zoom = 0.8;
	else if (button == SCROLL_DOWN)
		fractal->zoom = 1.2;
	else
		return (0);
	fractal->x_min = center_x - range_r / 2 * fractal->zoom;
	fractal->x_max = center_x + range_r / 2 * fractal->zoom;
	fractal->y_min = center_y - range_i / 2 * fractal->zoom;
	fractal->y_max = center_y + range_i / 2 * fractal->zoom;
	parse_pixels(fractal);
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



