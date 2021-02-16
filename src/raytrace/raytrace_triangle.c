/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:39:35 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/16 13:27:01 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	intersect_triangle(t_ray ray, t_triangle tr, t_hit *hit)
{
	t_hit		tmp_hit;
	t_vector	edge;
	t_vector	vt;
	t_vector	vp;
	double		denom;
	double		t;

	denom = dot(tr.normal, ray.dir);
	if (fabs(denom) < EPSILON)
		return (false);
	t = (-dot(tr.normal, ray.origin) + dot(tr.normal, tr.p1)) / denom;
	if (t < EPSILON || t > hit->t)
		return (false);
	tmp_hit.normal = tr.normal;
	tmp_hit.pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
	tmp_hit.t = distance(ray.origin, tmp_hit.pos);
	edge = vectorminus(tr.p2, tr.p1);
	vp = vectorminus(tmp_hit.pos, tr.p1);
	vt = vectorcross(edge, vp);
	if (dot(tr.normal, vt) < 0)
		return (false);
	edge = vectorminus(tr.p3, tr.p2);
	vp = vectorminus(tmp_hit.pos, tr.p2);
	vt = vectorcross(edge, vp);
	if (dot(tr.normal, vt) < 0)
		return (false);
	edge = vectorminus(tr.p1, tr.p3);
	vp = vectorminus(tmp_hit.pos, tr.p3);
	vt = vectorcross(edge, vp);
	if (dot(tr.normal, vt) < 0)
		return (false);
	hit->normal = tr.normal;
	hit->pos = tmp_hit.pos;
	hit->t = tmp_hit.t;
	return (true);
}

void	raytrace_triangle(t_ray ray, t_scene *scene, t_hit *hit, void **obj)
{
	t_list *item;
	t_triangle *triangle;

	item = scene->triangles;
	while (item)
	{
		triangle = item->content;
		if (intersect_triangle(ray, *triangle, hit))
		{
			*obj = triangle;
			hit->color = triangle->color;
		}
		item = item->next;
	}
}
