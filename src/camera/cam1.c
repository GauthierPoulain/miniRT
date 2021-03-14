/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:09:20 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/14 07:58:38 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
	t_vector	res;
	double		size_x;
	double		size_y;

	size_x = engine->size_x;
	size_y = engine->size_y;
	res.x = ((2 * ((x + .5) / size_x)) - 1) * (size_x / size_y)
		*tan((cam.fov / 2) *(PI / 180));
	res.y = (1 - (2 * ((y + .5) / size_y))) * tan((cam.fov / 2) *(PI / 180));
	res.z = 1;
	res = vec3_rotatexyz(res, cam.dir);
	return (new_ray(cam.pos, res));
}
