/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:47:27 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/12 10:44:11 by eedwards         ###   ########.fr       */
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
# define MANDELBROT 1
# define JULIA 2
# define BURNING 3

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
# define COLOR_ORANGE         0xFF8000FF

# include "../minilibx/mlx.h" //doesn't work at home
# include "../libft/libft.h"
# include <math.h> //fabs
# include <stdlib.h> //malloc free
# include <unistd.h> //write
# include <float.h> //for DBL_MAX
# include <string.h> //strerror
# include <errno.h> //errno

typedef struct	s_fractal{
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
	int		type;
}				t_fractal;

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
void		ft_error(t_fractal *fractal);

/* ************************************************************************** */
/*                                 MLX HOOKS                                  */
/* ************************************************************************** */
int			arrow_keys_hook(int keycode, t_fractal *fractal);
int			key_hook(int keycode, t_fractal *fractal);
int			mouse_hook(int button, int x, int y, t_fractal *fractal);
void		cycle_colors(t_fractal *fractal);
void		iteration_change(t_fractal *fractal, int keycode);

/* ************************************************************************** */
/*                              FRACTAL CALC                                  */
/* ************************************************************************** */
void		parse_pixels(t_fractal *fractal);
int			which_color(t_fractal *fractal, double xx, double yy);
int			ft_julia_check(double x, double y, t_fractal *fractal);
int			ft_mandelbrot_check(double cr, double ci, t_fractal *fractal);
int			ft_burning_ship_check(double cr, double ci, t_fractal *fractal);

#endif