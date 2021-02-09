/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:18:33 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/09 09:17:12 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	intersect_square(t_ray ray, t_square square, t_hit *hit)
{
	double		denom;
	double		t;

	denom = dot(square.normal, ray.dir);
	if (fabs(denom) > EPSILON)
	{
		t = dot(vectorminus(square.origin, ray.origin), square.normal) / denom;
		if (t < EPSILON || t > hit->t)
			return (false);
		if (distance(square.origin, vectoradd(ray.origin,
					vectormutliply(ray.dir, t))) > square.size)
			return (false);
		hit->normal = square.normal;
		hit->pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
		hit->t = distance(ray.origin, hit->pos);
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
