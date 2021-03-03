/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:49:01 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/03 15:48:54 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	process_normal_cy(t_ray ray, t_vector normal)
{
	if (dot(ray.dir, normal) < EPSILON)
		return (normal);
	return (vectormutliply(normal, -1));
}

double	intersect_caps_cy(t_ray ray, t_cylinder cy, t_vector pos)
{
	t_vector	tmp;
	double		a;
	double		b;
	double		t;

	t = 0;
	tmp = vectorminus(ray.origin, pos);
	a = dot(tmp, cy.dir);
	b = dot(ray.dir, cy.dir);
	if (!(b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0)))
		t = -a / b;
	return (t);
}

double	calc_c_cy(t_ray ray, t_cylinder cy, t_vector t, t_vector b)
{
	t_vector	a;

	a = vectorcross(vectorminus(ray.origin, b), vectorminus(t, b));
	return (dot(a, a) - (cy.radius * cy.radius * dot(vectorminus(t, b),
					vectorminus(t, b))));
}

t_vector	calclanormaleparceqttroplongue(t_cylinder cy, t_vector p)
{
	return (vectorminus(vectoradd(cy.pos, vectormutliply(get_normalize(cy.dir),
					dot(vectorminus(p, cy.pos), get_normalize(cy.dir)))), p));
}
