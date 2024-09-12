/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:32:58 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/12 11:05:33 by eedwards         ###   ########.fr       */
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
	exit (EXIT_SUCCESS);
}

//gives an error message if malloc fails then exits
void	ft_error(t_fractal *fractal)
{
	ft_printf("Error: %s\n", strerror(errno));
	ft_close(fractal);
}
