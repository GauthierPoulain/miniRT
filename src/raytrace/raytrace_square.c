/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:11:58 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/02 13:24:57 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	get_proj(t_vector origin, t_vector v1, t_vector v2)
{
	t_vector	proj;
	t_vector	a;
	t_vector	b;

	a = vectorminus(v1, origin);
	b = vectorminus(v2, origin);
	proj = vectormutliply(a, dot(b, a) / pow(magnitude(a), 2));
	// printf("a = %.20f\n", magnitude(a));
	return (fabs(distance(get_vector(0, 0, 0), proj)));
}

bool	check_edges(t_square sq, t_hit hit)
{
	t_vector	r0;
	t_vector	p;

	r0 = sq.normal;
	r0 = vectorcross(r0, apply_rot(sq.normal, sq.normal, get_vector(0, 1, 0)));
	p = vectoradd(sq.origin, vectormutliply(r0, sq.size));
	if (get_proj(sq.origin, p, hit.pos) > sq.size)
		return (false);
	r0 = vectorcross(r0, apply_rot(sq.normal, r0, get_vector(0, 1, 0)));
	p = vectoradd(sq.origin, vectormutliply(r0, sq.size));
	// printf("x = %f, y = %f, z = %f\n", p.x, p.y, p.z);
	if (get_proj(sq.origin, p, hit.pos) > sq.size)
		return (false);
	// r0 = vectorcross(get_vector(1, 0, 0), r0);
	// p = vectoradd(sq.origin, vectormutliply(r0, sq.size));
	// if (get_proj(sq.origin, p, hit.pos) > sq.size)
	// 	return (false);
	// r0 = vectorcross(get_vector(1, 0, 0), r0);
	// p = vectoradd(sq.origin, vectormutliply(r0, sq.size));
	// if (get_proj(sq.origin, p, hit.pos) > sq.size)
	// 	return (false);
	// printf("salut = %.20f\n", get_proj(sq.origin, p, hit.pos));
	return (true);
}

bool	intersect_square(t_ray ray, t_square sq, t_hit *hit)
{
	double		denom;
	double		t;
	t_vector	p;
	t_hit		tmp_hit;

	denom = dot(sq.normal, ray.dir);
	if (fabs(denom) <= EPSILON)
		return (false);
	t = dot(vectorminus(sq.origin, ray.origin), sq.normal) / denom;
	p = vectoradd(ray.origin, vectormutliply(ray.dir, t));
	if (t < EPSILON || t > hit->t)
		return (false);
	tmp_hit.pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
	if (!check_edges(sq, tmp_hit))
		return (false);
	hit->normal = sq.normal;
	hit->t = t;
	hit->pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
	return (true);
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
