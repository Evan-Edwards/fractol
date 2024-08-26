/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:47:27 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/26 14:39:56 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define WIDTH	800
#define HEIGHT	800
#define MALLOC_ERR_MESSAGE "Malloc failed"
#define INVALID_ARGS_MESSAGE "Input invalid. Examples of valid input:\n ./fractol mandelbrot \n ./fractol julia <num 1> <num 2>"
#define ESC_KEY 65307
#define C_KEY 99
#define LEFT_KEY 65361
#define UP_KEY 65362
#define RIGHT_KEY 65363
#define DOWN_KEY 65364
#define PLUS_KEY 107
#define MINUS_KEY 109
#define SCROLL_UP 4
#define SCROLL_DOWN 5


// Define colors using RGBA values (with transparency)
#define COLOR_BLACK   0x000000FF
#define COLOR_WHITE   0xFFFFFFFF
#define COLOR_RED     0xFF0000FF
#define COLOR_GREEN   0x00FF00FF
#define COLOR_BLUE    0x0000FFFF
#define COLOR_YELLOW  0xFFFF00FF
#define COLOR_CYAN    0x00FFFFFF
#define COLOR_MAGENTA 0xFF00FFFF

// Define psychedelic colors
#define COLOR_PSY_1   0xFF00FF80
#define COLOR_PSY_2   0x00FF80FF
#define COLOR_PSY_3   0x80FF00FF
#define COLOR_PSY_4   0xFF8000FF
#define COLOR_PSY_5   0x00FF00FF

#include "minilibx/mlx.h" //doesn't work at home
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h> //DELETE
#include <stdlib.h> //malloc free
#include <unistd.h> //write
#include <float.h> //for DBL_MAX

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
	int		*color_array;
	double	zoom;
}				t_fractal;


int			*set_color_array(void);

/* ************************************************************************** */
/*                             INPUT VALIDATION                               */
/* ************************************************************************** */
int			input_check(int ac, char **av);
int			check_julia_input(char *arg);

/* ************************************************************************** */
/*                                 ATOD                                       */
/* ************************************************************************** */
double		ft_atod(const char *str);
double		after_dec(const char *str);

/* ************************************************************************** */
/*                                 MLX UTILS                                  */
/* ************************************************************************** */
void		fractal_init(t_fractal *fractal);
int			*set_color_array(void);
int			ft_close(t_fractal *fractal);
void		malloc_error(t_fractal *fractal);
void		pixel_put_image(t_fractal *img, int x, int y, int color);

/* ************************************************************************** */
/*                                 MLX HOOKS                                  */
/* ************************************************************************** */
int			arrow_keys_hook(int	keycode, t_fractal *fractal);
int			key_hook(int keycode, t_fractal *fractal);
int			mouse_hook(int button, int x, int y, t_fractal *fractal);
void		cycle_colors(t_fractal *fractal);

/* ************************************************************************** */
/*                              FRACTAL CALC                                  */
/* ************************************************************************** */
void		parse_pixels(t_fractal *fractal);
int			which_color(t_fractal *fractal, double xx, double yy);
int			ft_julia_check(double x, double y, t_fractal *fractal);
int			ft_mandelbrot_check(double x, double y);
double		scaleBetween(double unscaled, double new_min, double new_max,
										 double old_min, double old_max);

#endif