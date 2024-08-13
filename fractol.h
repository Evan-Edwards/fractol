/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:47:27 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/13 15:35:08 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL
#define FRACTAL

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length; //number of bytes used to store single row of pixels
	int		endian; //determines how pixels stored in memory (least or most signifcant first)
}				t_img;



#endif