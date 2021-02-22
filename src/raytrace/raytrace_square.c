/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:11:58 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/22 12:52:52 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	intersect_square(t_ray ray, t_square square, t_hit *hit)
{
	double		denom;
	double		t;
	t_vector	p;

	denom = dot(square.normal, ray.dir);
	if (fabs(denom) > EPSILON)
	{
		t = dot(vectorminus(square.origin, ray.origin), square.normal) / denom;
		p = vectoradd(ray.origin, vectormutliply(ray.dir, t));
		if (distance(p, square.origin) > square.size)
			return (false);
		if (t < EPSILON || t > hit->t)
			return (false);
		hit->normal = square.normal;
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
