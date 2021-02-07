/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:02:09 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/07 13:29:39 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray		new_ray(t_vector origin, t_vector dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir;
	ray.min = INFINITY;
	return (ray);
}

t_ray		init_ray(t_engine *engine, t_cam cam, int x, int y)
{
	t_vector	dir;

	dir = set_ray_direction(engine, cam, x, y);
	return (new_ray(cam.pos, dir));
}

t_vector	set_ray_direction(t_engine *engine, t_cam cam, int x, int y)
{
	t_vector	dir;
	double		a;
	double		b;
	double		c;

	a = y + 0.5 - engine->size_y * 0.5;
	b = x + 0.5 - engine->size_x * 0.5;
	c = ft_math_max(engine->size_x, engine->size_y)
	/ (2 * tan(to_rad(cam.fov) / 180.0));
	dir.y = -1 * a + 0 * b + 0 * c;
	dir.x = 0 * a + 1 * b + 0 * c;
	dir.z = 0 * a + 0 * b + 1 * c;
	// dir = rot_vect(dir, 1, 'x');
	// dir = rot_vect(dir, 0, 'y');
	// dir = rot_vect(dir, 1, 'z');
	return (dir);
}
