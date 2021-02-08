/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:23:47 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/07 17:05:15 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double		ft_max_double(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double		ft_min_double(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

t_vector	normaltodeg(t_vector vec)
{
	vec.x = to_rad(90 * vec.x);
	vec.y = to_rad(90 * vec.y);
	vec.z = to_rad(90 * vec.z);
	return (vec);
}