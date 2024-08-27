/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:13:58 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/27 12:57:35 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *str)
{
	double	result;
	int		sign;

	sign = 1;
	result = 0;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	//printf("Atod %f\n", result);
	if (*str == '.')
	{
		printf("after_dec %f\n", after_dec(str + 1));
		result += after_dec(str + 1);
	}
	//printf("Test %f\n", result);
	return ((result * sign));
}

double	after_dec(const char *str)
{
	double	dec_place;
	double	result;

	result = 0;
	dec_place = 0.1;
	while (*str >= '0' && *str <= '9' && *str && dec_place > 0)
	{
		result += (*str - '0') * dec_place;
		dec_place /= 10;
		str++;
	}
	return (result);
}