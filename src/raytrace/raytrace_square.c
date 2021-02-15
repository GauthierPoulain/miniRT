/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:18:33 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/15 14:05:04 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double		mod(t_vector v)
{
	return (sqrt(dot(v, v)));
}

double		vcos(t_vector a, t_vector b)
{
	return (dot(a, b) / (mod(a) * mod(b)));
}

t_hit	custom_intersect_plane(t_ray ray, t_square square, t_hit *hit)
{
	double		denom;
	double		t;
	t_hit		chit;

	chit.t = INFINITY;
	denom = dot(square.normal, ray.dir);
	if (fabs(denom) > EPSILON)
	{
		t = dot(vectorminus(square.origin, ray.origin), square.normal) / denom;
		if (t < EPSILON || t > hit->t)
			return (chit);
		chit.normal = square.normal;
		chit.pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
		chit.t = distance(ray.origin, chit.pos);
		return (chit);
	}
	return (chit);
}

bool	intersect_square(t_ray ray, t_square square, t_hit *hit)
{
	t_hit	planehit;
	double	cos1;
	t_vector	half_size;
	t_vector	floor;
	double	limit;
	t_vector	ctoip;

	planehit = custom_intersect_plane(ray, square, hit);
	if (planehit.t == INFINITY)
		return (false);
	if (fabs(square.normal.y == 1))
		floor = get_vector(1, 0, 0);
	else
		floor = get_vector(0, 1, 0);
	half_size = vectorcross(square.normal, floor);
	ctoip = vectorminus(vectoradd(square.origin, vectormutliply(square.normal, planehit.t)), square.origin);
	cos1 = fabs(vcos(half_size, square.origin));
	if (cos1 < sqrt(2) / 2)
		cos1 = cos(M_PI_2 - acos(cos1));
	limit = (square.size / 2) / cos1;
	if (mod(ctoip) <= limit)
	{
		hit->t = planehit.t;
		hit->normal = square.normal;
		hit->pos = planehit.pos;
		return (true);
	}
	return (false);
}

void	raytrace_square(t_ray ray, t_scene *scene, t_hit *hit, void **obj)
{
	t_list		*item;
	t_square	*square;

	item = scene->squares;
	while (item)
	{
		square = item->content;
		if (intersect_square(ray, *square, hit))
		{
			*obj = square;
			hit->color = square->color;
		}
		item = item->next;
	}
}
