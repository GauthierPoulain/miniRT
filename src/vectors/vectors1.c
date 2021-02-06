/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:44:35 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 09:45:28 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	get_vector(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vector	vectoradd(t_vector s1, t_vector s2)
{
	return (get_vector(s1.x + s2.x, s1.y + s2.y, s1.z + s2.z));
}

t_vector	vectorminus(t_vector s1, t_vector s2)
{
	return (get_vector(s1.x - s2.x, s1.y - s2.y, s1.z - s2.z));
}

t_vector	vectormutliply(t_vector s1, double value)
{
	return (get_vector(s1.x * value, s1.y * value, s1.z * value));
}

t_vector	vectordivide(t_vector s1, double value)
{
	return (get_vector(s1.x / value, s1.y / value, s1.z / value));
}
