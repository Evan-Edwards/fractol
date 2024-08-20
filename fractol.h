/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:47:27 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/20 11:29:14 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define WIDTH	800
#define HEIGHT	800
#define MALLOC_ERR_MESSAGE "Malloc failed"
#define INVALID_ARGS_MESSAGE "Input invalid. Examples of valid input:\n ./fractol mandelbrot \n ./fractol julia <num 1> <num 2>"

#include "minilibx/mlx.h" //doesn't work at home
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdlib.h> //malloc free
#include <unistd.h> //write

typedef struct	s_fractal {
	char	*title;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bbp;
	int		line_length; //number of bytes used to store single row of pixels
	int		endian; //determines how pixels stored in memory (least or most signifcant first)
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	jul_arg1;
	double	jul_arg2;
}				t_fractal;

typedef struct	s_complex
{
	double	real;
	double	imaginary;
}				t_complex;


int			ft_check_valid(char *arg);
int			input_check(int ac, char **av);

/* ************************************************************************** */
/*                                 MLX UTILS                                  */
/* ************************************************************************** */
void		fractal_init(t_fractal *fractal);
int			ft_close(t_fractal *fractal);
int			esc_key_hook(int keycode, t_fractal *fractal);
int			mouse_hook(int button, int x, int y, t_fractal *fractal);
void		malloc_error(void);
void		pixel_put_image(t_fractal *img, int x, int y, int color);


/* ************************************************************************** */
/*                                    MATH                                    */
/* ************************************************************************** */
double		absolute_complex(t_complex a);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	squared_complex(t_complex a);
double		scaleBetween(double unscaled, double new_min, double new_max,
										 double old_min, double old_max);

/* ************************************************************************** */
/*                              FRACTAL CALC                                  */
/* ************************************************************************** */
void		parse_pixels(t_fractal *fractal);
int			which_color(t_fractal *fractal, double xx, double yy);
void		ft_set_compl_values(double real, double imaginary, t_complex *cz);
int			ft_julia_check(double x, double y, t_fractal *fractal);
int			ft_mandelbrot_check(double x, double y);

#endif