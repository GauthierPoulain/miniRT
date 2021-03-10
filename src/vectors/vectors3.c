/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:00:06 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/10 14:38:01 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	distance(t_vector p1, t_vector p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)
			+ pow(p2.z - p1.z, 2)));
}

t_vector	vectorcross(t_vector v1, t_vector v2)
{
	t_vector	cross;

	cross.x = v1.y * v2.z - v1.z * v2.y;
	cross.y = v1.z * v2.x - v1.x * v2.z;
	cross.z = v1.x * v2.y - v1.y * v2.x;
	return (cross);
}

double	magnitude(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector	calc_rot(t_vector *c2, t_vector *c3, t_vector rot, t_vector to)
{
	t_vector	c1;
	t_vector	v;
	double		c;
	double		s;
	double		r;

	v = vectorcross(to, rot);
	c = dot(rot, to);
	s = pow(magnitude(v), 2);
	r = ((1 - c) / s);
	c1 = get_vector(-r * (pow(v.y, 2) + pow(v.z, 2)) + 1, r * v.x
			* v.y - v.z, r * v.x * v.z + v.y);
	*c2 = get_vector(r * v.x * v.y + v.z, -r * (pow(v.x, 2)
				+ pow(v.z, 2)) + 1, r * v.y * v.x - v.x);
	*c3 = get_vector(r * v.x * v.z - v.y, r * v.y * v.z - v.x, -r
			* (pow(v.x, 2) + pow(v.y, 2)) + 1);
	return (c1);
}

t_vector	apply_rot(t_vector pos, t_vector dir, t_vector rot)
{
	t_vector	c1;
	t_vector	c2;
	t_vector	c3;

	// if (dir.x == 0 && dir.y < 0 && dir.z == 0)
		// pos = get_vector(pos.x, pos.y, -pos.z);
	if (!(dir.x == 0 && dir.y != 0 && dir.z == 0))
	{
		c1 = calc_rot(&c2, &c3, rot, dir);
		pos = get_vector(dot(c1, pos), dot(c2, pos), pos.z);
	}
	return (pos);
}
