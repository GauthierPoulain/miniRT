/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:45:55 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/20 06:41:34 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	intersect_sphere(const t_ray ray, const t_sphere sphere, t_hit *hit)
{
	double		t1;
	double		t2;
	t_vector	vect;

	vect = vectorminus(ray.origin, sphere.pos);
	if (!secdegsolve(get_vector(dot(ray.dir, ray.dir), 2 * dot(ray.dir, vect),
				dot(vect, vect) - pow(sphere.radius, 2)), &t1, &t2))
		return (false);
	if ((t1 < 0 && t2 < 0) || (t1 > hit->t && t2 > hit->t))
		return (false);
	else if (t1 <= 0)
		t1 = t2;
	else if (t2 <= 0)
		t2 = t1;
	hit->t = ft_dmin(t1, t2);
	hit->pos = vectoradd(ray.origin, vectormutliply(ray.dir, t2));
	hit->normal = get_normalize(vectorminus(hit->pos, sphere.pos));
	hit->pos = vectoradd(hit->pos, vectormutliply(hit->normal, EPSILON));
	return (true);
}

void	raytrace_spheres(t_ray ray, t_scene *scene, t_hit *hit, void **obj)
{
	t_list		*item;
	t_sphere	*sphere;

	item = scene->spheres;
	while (item)
	{
		sphere = item->content;
		if (intersect_sphere(ray, *sphere, hit))
		{
			*obj = sphere;
			hit->color = sphere->color;
		}
		item = item->next;
	}
}
