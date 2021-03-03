/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:11:58 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/03 14:55:27 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	get_proj(t_vector origin, t_vector dir, t_vector pos)
{
	t_vector	relative_pos;

	relative_pos = vectorminus(pos, origin);
	return (fabs(dot(dir, relative_pos)));
}

bool	check_edges(t_square sq, t_hit hit)
{
	t_vector	up;
	t_vector	right;

	if (fabs(sq.normal.x) == 1 && sq.normal.y == 0 && sq.normal.z == 0)
		up = get_vector(0, 1, 0);
	else
		up = get_normalize(vectorcross(get_vector(1, 0, 0), sq.normal));
	if (get_proj(sq.origin, up, hit.pos) > sq.size)
		return (false);
	right = get_normalize(vectorcross(up, sq.normal));
	if (get_proj(sq.origin, right, hit.pos) > sq.size)
		return (false);
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
