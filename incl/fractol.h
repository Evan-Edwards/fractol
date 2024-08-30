/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:47:27 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/30 11:51:47 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH	800
# define HEIGHT	800
# define ESC_KEY 65307
# define C_KEY 99
# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define PLUS_KEY 65451
# define MINUS_KEY 65453
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// Define colors using RGBA values (with transparency)

# define COLOR_WHITE   0xFFFFFFFF
# define COLOR_RED     0xFF0000FF
# define COLOR_GREEN   0x00FF00FF
# define COLOR_BLUE    0x0000FFFF
# define COLOR_YELLOW  0xFFFF00FF
# define COLOR_CYAN    0x00FFFFFF
# define COLOR_SPRING_GREEN   0x00FF80FF
# define COLOR_CHARTREUSE   0x80FF00FF
# define COLOR_ORANGE   0xFF8000FF
# define COLOR_LIME   0x00FF00FF

# define COLOR_BLACK          0x00000000
# define COLOR_DARK_PURPLE    0x2E004FFF
# define COLOR_PURPLE         0x5C009FFF
# define COLOR_VIOLET         0x8A00EFFF
# define COLOR_MAGENTA        0xFF00FFFF
# define COLOR_HOT_PINK       0xFF69B4FF
# define COLOR_PINK           0xFF85CFFF
# define COLOR_LIGHT_PINK     0xFFB6C1FF
# define COLOR_NEON_PINK      0xFF6FFF
# define COLOR_PSYCHADELIC    0xFF00FF00

# include "../minilibx/mlx.h" //doesn't work at home
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h> //DELETE
# include <stdlib.h> //malloc free
# include <unistd.h> //write
# include <float.h> //for DBL_MAX

typedef struct	s_fractal {
	char	*title;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bbp;
	int		line_len;
	int		endian;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	jul_arg1;
	double	jul_arg2;
	int		*color_array;
	double	zoom;
	double	iterations;
}				t_fractal;

/* ************************************************************************** */
/*                             INPUT VALIDATION                               */
/* ************************************************************************** */
int			input_check_bonus(int ac, char **av);
int			check_julia_input(char *arg);

/* ************************************************************************** */
/*                                 ATOD                                       */
/* ************************************************************************** */
double		ft_atod(const char *str);
double		after_dec(const char *str);

/* ************************************************************************** */
/*                               FRACTAL INIT                                 */
/* ************************************************************************** */
void		fractal_mlx_init(t_fractal *fractal);
void		fractal_values_init(t_fractal *fractal, char **av);
int			*set_color_array(void);
void		pixel_put_image(t_fractal *img, int x, int y, int color);

/* ************************************************************************** */
/*                               ERROR & CLOSE                                */
/* ************************************************************************** */
int			ft_close(t_fractal *fractal);
void		malloc_error(t_fractal *fractal);

/* ************************************************************************** */
/*                                 MLX HOOKS                                  */
/* ************************************************************************** */
int			key_hook(int keycode, t_fractal *fractal);
int			mouse_hook(int button, t_fractal *fractal);
void		iteration_change(t_fractal *fractal, int keycode);

/* ************************************************************************** */
/*                              FRACTAL CALC                                  */
/* ************************************************************************** */
void		parse_pixels(t_fractal *fractal);
int			which_color(t_fractal *fractal, double xx, double yy);
int			ft_julia_check(double x, double y, t_fractal *fractal);
int			ft_mandelbrot_check(double cr, double ci, t_fractal *fractal);
double		scaleBetween(double unscaled, double new_min, double new_max,
				double old_min, double old_max);

#endif