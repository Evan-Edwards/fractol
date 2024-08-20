/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:45:38 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/20 12:49:51 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*  void	all_pixels_red(t_fractal *fractal)
{
	int	x;
	int	y;
	int	red;
	
	red = 16711680;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			pixel_put_image(fractal, x, y, red);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}  */

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (input_check(ac, av))
	{
		ft_putstr("Input valid\n");
		fractal_init_values(&fractal, av);
		fractal_init(&fractal);
		//all_pixels_red(&fractal);
		parse_pixels(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd(INVALID_ARGS_MESSAGE, 2);
		return (0); //TODO
	} 
	return (0);
}

