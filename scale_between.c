/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_between.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:42:48 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/28 15:42:59 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//used to find the x(real) and y(imaginary) values of each pixel based on window
double	scaleBetween(double unscaled, double new_min, double new_max, 
										double old_min, double old_max)
{
	return((new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min);
}
