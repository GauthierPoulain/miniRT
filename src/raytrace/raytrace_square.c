/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:11:58 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/23 16:09:25 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static double	get_ray_t(double size)
{
	return (size);
}

bool	intersect_square(t_ray ray, t_square sq, t_hit *hit)
{
	double		denom;
	double		t;
	t_vector	p;
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	t_vector	p4;
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
		r0.z = to_rad(sq.normal.z * 90);

		printf("r0 y = %f\n", r0.y);

		p1 = vectoradd(sq.origin, vectormutliply(r0, get_ray_t(sq.size)));
		r0.x = to_rad(sq.normal.x * 90);
		p2 = vectoradd(sq.origin, vectormutliply(r0, get_ray_t(sq.size)));
		r0.x = to_rad(sq.normal.x * 180);
		p3 = vectoradd(sq.origin, vectormutliply(r0, get_ray_t(sq.size)));
		r0.x = to_rad(sq.normal.x * 270);
		p4 = vectoradd(sq.origin, vectormutliply(r0, get_ray_t(sq.size)));

	printf("%f\n", p1.x);
		if (dot(vectorminus(sq.origin, p1), vectorminus(sq.origin, tmp_hit.pos)) > sq.size)
			return (false);
		if (dot(vectorminus(sq.origin, p2), vectorminus(sq.origin, tmp_hit.pos)) > sq.size)
			return (false);
		if (dot(vectorminus(sq.origin, p3), vectorminus(sq.origin, tmp_hit.pos)) > sq.size)
			return (false);
		if (dot(vectorminus(sq.origin, p4), vectorminus(sq.origin, tmp_hit.pos)) > sq.size)
			return (false);


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
