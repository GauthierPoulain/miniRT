/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:02:09 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/19 14:11:55 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	new_ray(t_vector origin, t_vector dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = get_normalize(dir);
	ray.min = INFINITY;
	return (ray);
}

t_ray	init_ray(t_engine *engine, t_cam cam, int x, int y)
{
	t_vector	dir;

	dir = set_ray_direction(engine, cam, x, y);
	return (new_ray(cam.pos, dir));
}

t_vector	set_ray_direction(t_engine *engine, t_cam cam, int x, int y)
{
	t_vector	dir;

	dir = get_vector(
			(x - engine->size_x / 2) + cam.dir.x,
			(engine->size_y / 2 - y) + cam.dir.y,
			((engine->size_y / 2) / tan((cam.fov * PI / 180) / 2))
			+ cam.dir.z);
	dir = vectoradd(dir, cam.dir);
	return (dir);
}
