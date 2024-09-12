/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:13:58 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/12 13:02:27 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//makes arguements given for julia into doubles
double	ft_atod(const char *str)
{
	double	result;
	double	dec_place;
	int		sign;

	sign = 1;
	result = 0;
	dec_place = 0.1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (*str == '.')
	{
		while (*++str >= '0' && *str <= '9')
		{
			result += (*str - '0') * dec_place ;
			dec_place /= 10;
		}
	}
	return ((result * sign));
}
