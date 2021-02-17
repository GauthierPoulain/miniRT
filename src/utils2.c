/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:23:47 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/16 15:36:22 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	normaltodeg(t_vector vec)
{
	vec.x = to_rad(90 * vec.x);
	vec.y = to_rad(90 * vec.y);
	vec.z = to_rad(90 * vec.z);
	return (vec);
}

t_vector	get_triangle_normal(t_triangle *triangle)
{
	t_vector	a;
	t_vector	b;

	a = vectorminus(triangle->p2, triangle->p1);
	b = vectorminus(triangle->p3, triangle->p1);
	return (get_normalize(vectorcross(a, b)));
}

double			ft_max_double(double a, double b)
{
	if(a > b)
		return(a);
	return (b);
}

double			ft_min_double(double a, double b)
{
	if(a < b)
		return(a);
	return (b);
}
