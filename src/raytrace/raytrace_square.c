/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:11:58 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/24 15:34:44 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	get_pimped(t_vector origin, t_vector v1, t_vector v2)
{
	double		angle;
	t_vector	nv1;
	t_vector	nv2;

	nv1 = vectorminus(origin, v1);
	nv2 = vectorminus(origin, v2);
	angle = dot(nv1, nv2) * 180 / PI;
	printf("angle = %f\n", angle);
	return (dot(vectorminus(origin, v1), vectorminus(origin, v2)) * cos(angle));
}

bool	intersect_square(t_ray ray, t_square sq, t_hit *hit)
{
	double		denom;
	double		t;
	t_vector	p;
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	// t_vector	p4;
	t_vector	r0;

	t_hit	tmp_hit;

	denom = dot(sq.normal, ray.dir);
	if (fabs(denom) > EPSILON)
	{
		t = dot(vectorminus(sq.origin, ray.origin), sq.normal) / denom;
		p = vectoradd(ray.origin, vectormutliply(ray.dir, t));
		if (t < EPSILON || t > hit->t)
			return (false);

		tmp_hit.pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
		
		r0 = sq.normal;


		r0 = vectorcross(r0, get_vector(1, 0, 0));
		p1 = vectoradd(sq.origin, vectormutliply(r0, sq.size));
		r0 = vectorcross(get_vector(0, 1, 0), r0);
		p2 = vectoradd(sq.origin, vectormutliply(r0, sq.size));
		r0 = vectorcross(get_vector(0, 1, 0), r0);
		p3 = vectoradd(sq.origin, vectormutliply(r0, sq.size));
		// r0 = vectorcross(get_vector(0, 1, 0), r0);
		// p4 = vectoradd(sq.origin, vectormutliply(r0, sq.size));

		// printf("p1 x = %f, y = %f, z = %f\n", p1.x, p1.y, p1.z);
		// printf("p2 x = %f, y = %f, z = %f\n", p2.x, p2.y, p2.z);
		// printf("p3 x = %f, y = %f, z = %f\n", p3.x, p3.y, p3.z);
		// printf("p4 x = %f, y = %f, z = %f\n", p4.x, p4.y, p4.z);


		// if (fabs(dot(vectorminus(sq.origin, p1), vectorminus(sq.origin, tmp_hit.pos))) > sq.size)
		// if (fabs(get_pimped(sq.origin, p1, tmp_hit.pos)) > sq.size)
		// 	return (false);
		// if (fabs(get_pimped(sq.origin, p2, tmp_hit.pos)) > sq.size)
		// 	return (false);
		// if (dot(vectorminus(sq.origin, p3), vectorminus(sq.origin, tmp_hit.pos)) > sq.size)
		// 	return (false);
		// if (dot(vectorminus(sq.origin, p4), vectorminus(sq.origin, tmp_hit.pos)) > sq.size)
		// 	return (false);

		printf("size = %f\n", sq.size);
		printf("dot = %f\n", fabs(dot(vectorminus(sq.origin, p1), vectorminus(sq.origin, p3))));
		printf("dotv2 = %f\n", fabs(fabs(get_pimped(sq.origin, p1, p3))));

		hit->normal = sq.normal;
		hit->t = t;
		hit->pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
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
