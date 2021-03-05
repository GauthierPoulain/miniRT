/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:02:09 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/05 11:58:50 by gapoulai         ###   ########lyon.fr   */
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
	t_vector	pixel;
	t_vector	axis;
	double		size_x;
	double		size_y;

	axis = get_vector(0, 1, 0);
	size_x = engine->size_x;
	size_y = engine->size_y;
	pixel.x = ((2 * ((x + .5) / size_x)) - 1) * (size_x / size_y)
		* tan((cam.fov / 2) * (PI / 180));
	pixel.y = (1 - (2 * ((y + .5) / size_y))) * tan((cam.fov / 2) * (PI / 180));
	pixel.z = 1;
	if (!(cam.dir.x == 0 && cam.dir.y > 0 && cam.dir.z == 0))
		pixel = apply_rot(pixel, cam.dir, axis);
	return (pixel);
}
