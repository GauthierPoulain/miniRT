/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:37:38 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/20 02:54:05 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	intersect_plane(t_ray ray, t_plane plane, t_hit *hit)
{
	double		denom;
	double		t;

	denom = dot(plane.normal, ray.dir);
	if (fabs(denom) > EPSILON)
	{
		t = dot(vectorminus(plane.origin, ray.origin), plane.normal) / denom;
		if (t < EPSILON || t > hit->t)
			return (false);
		hit->normal = plane.normal;
		hit->t = t;
		hit->pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
		return (true);
	}
	return (false);
}

void	raytrace_planes(t_ray ray, t_scene *scene, t_hit *hit, void **obj)
{
	t_list	*item;
	t_plane	*plane;

	item = scene->planes;
	while (item)
	{
		plane = item->content;
		if (intersect_plane(ray, *plane, hit))
		{
			*obj = plane;
			hit->color = plane->color;
		}
		item = item->next;
	}
}
