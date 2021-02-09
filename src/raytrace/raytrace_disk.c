/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_disk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:56:32 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/09 15:11:32 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	intersect_disk(t_ray ray, t_disk disk, t_hit *hit)
{
	double		denom;
	double		t;

	denom = dot(disk.normal, ray.dir);
	if (fabs(denom) > EPSILON)
	{
		t = dot(vectorminus(disk.origin, ray.origin), disk.normal) / denom;
		if (t < EPSILON || t > hit->t)
			return (false);
		if (distance(disk.origin, vectoradd(ray.origin,
					vectormutliply(ray.dir, t))) > disk.size)
			return (false);
		hit->normal = disk.normal;
		hit->pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
		hit->t = distance(ray.origin, hit->pos);
		return (true);
	}
	return (false);
}

void	raytrace_disk(t_ray ray, t_scene *scene, t_hit *hit, void **obj)
{
	t_list	*item;
	t_disk	*disk;

	item = scene->disks;
	while (item)
	{
		disk = item->content;
		if (intersect_disk(ray, *disk, hit))
		{
			*obj = disk;
			hit->color = disk->color;
		}
		item = item->next;
	}
}
