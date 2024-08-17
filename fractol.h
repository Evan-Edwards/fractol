/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:47:27 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/17 13:25:47 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL
#define FRACTAL

#include "minilibx/mlx.h" //doesn't work at home
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdlib.h> //malloc free
#include <unistd.h> //write

#define WIDTH	800
#define HEIGHT	800

typedef struct	s_vars {
	
}				t_vars;

typedef struct	s_fractal {
	char	*title;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bbp;
	int		line_length; //number of bytes used to store single row of pixels
	int		endian; //determines how pixels stored in memory (least or most signifcant first)
	int		max_x;
	int		max_y;
}				t_fractal;

typedef struct	s_complex
{
	double	real;
	double	imaginary;
	double	absolute_2;
}				t_complex;

int		ft_close(t_vars *vars);
int		ft_julia_check(int x, int y, char **av);
int		ft_mandelbrot_check(int x, int y);
void	ft_set_compl_values(int real, int imaginary, t_complex *cz);
void	ft_set_max_xy(t_img *img);
int		key_hook(int keycode, t_vars *vars);
void	pixel_put_image(t_img *img, int x, int y, int color);
void	parse_pixels(t_img *img, char **av);


#endif