/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:32:58 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/28 15:44:36 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	ft_putstr_fd("Malloc failed", 2);
	ft_close(fractal);
}
