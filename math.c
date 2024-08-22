/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:21:17 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/22 16:59:25 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

//adds 2 complex numbers together
t_complex sum_complex(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.real = a.real + b.real;
	sum.imaginary = a.imaginary + b.imaginary;
	return (sum);
}

//squares complex number. It works out to x^2 - y^2 + 2xyi
t_complex	squared_complex(t_complex a)
{
	t_complex	result;
	
	result.real = a.real * a.real - a.imaginary * a.imaginary;
	result.imaginary = 2 * a.real * a.imaginary;
	return (result);
}
//gives the absolute value for a complex number, useful to see if a coordinate
//stays in bounds. Formula = square root of (x * x + y * y) (pythagorean theorem);
double	absolute_complex(t_complex a)
{
	double	result;

	result = sqrt(a.real * a.real + a.imaginary * a.imaginary);
	return (result);
}


double	scaleBetween(double unscaled, double new_min, double new_max, 
										double old_min, double old_max)
{
	return((new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min);
}