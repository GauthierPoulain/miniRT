/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:39:35 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/23 12:40:38 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	calc_edge1(t_triangle tr, t_hit hit)
{
	t_vector	edge;
	t_vector	vt;
	t_vector	vp;

	edge = vectorminus(tr.p2, tr.p1);
	vp = vectorminus(hit.pos, tr.p1);
	vt = vectorcross(edge, vp);
	if (dot(tr.normal, vt) < 0)
		return (false);
	return (true);
}

bool	calc_edge2(t_triangle tr, t_hit hit)
{
	t_vector	edge;
	t_vector	vt;
	t_vector	vp;

	edge = vectorminus(tr.p3, tr.p2);
	vp = vectorminus(hit.pos, tr.p2);
	vt = vectorcross(edge, vp);
	if (dot(tr.normal, vt) < 0)
		return (false);
	return (true);
}

bool	calc_edge3(t_triangle tr, t_hit hit)
{
	t_vector	edge;
	t_vector	vt;
	t_vector	vp;

	edge = vectorminus(tr.p1, tr.p3);
	vp = vectorminus(hit.pos, tr.p3);
	vt = vectorcross(edge, vp);
	if (dot(tr.normal, vt) < 0)
		return (false);
	return (true);
}

bool	intersect_triangle(t_ray ray, t_triangle tr, t_hit *hit)
{
	t_hit		tmp_hit;
	double		denom;
	double		t;

	denom = dot(tr.normal, ray.dir);
	if (fabs(denom) <= EPSILON)
		return (false);
	t = (-dot(tr.normal, ray.origin) + dot(tr.normal, tr.p1)) / denom;
	if (t <= EPSILON || t >= hit->t)
		return (false);
	tmp_hit.normal = tr.normal;
	tmp_hit.pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
	tmp_hit.t = distance(ray.origin, tmp_hit.pos);
	if (!calc_edge1(tr, tmp_hit) || !calc_edge2(tr, tmp_hit)
		|| !calc_edge3(tr, tmp_hit))
		return (false);
	hit->normal = tmp_hit.normal;
	hit->pos = tmp_hit.pos;
	hit->t = tmp_hit.t;
	return (true);
}

void	raytrace_triangle(t_ray ray, t_scene *scene, t_hit *hit, void **obj)
{
	t_list		*item;
	t_triangle	*triangle;

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
