/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:09:20 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/11 13:18:16 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector vec3_rotatex(t_vector vec3, double alpha)
{
	double	y;
	double	z;

	y = vec3.y * cos(PI * alpha) - vec3.z * sin(PI * alpha);
	z = vec3.y * sin(PI * alpha) + vec3.z * cos(PI * alpha);
	return (get_vector(vec3.x, y, z));
}

t_vector vec3_rotatey(t_vector vec3, double beta)
{
	double	x;
	double	z;

	x = vec3.x * cos(PI * beta) + vec3.z * sin(PI * beta);
	z = vec3.x * -sin(PI * beta) + vec3.z * cos(PI * beta);
	return (get_vector(x, vec3.y, z));
}

t_vector vec3_rotatez(t_vector vec3, double gamma)
{
	double	x;
	double	y;

	x = vec3.x * cos(PI * gamma) - vec3.y * sin(PI * gamma);
	y = vec3.x * sin(PI * gamma) + vec3.y * cos(PI * gamma);
	return (get_vector(x, y, vec3.z));
}

t_vector vec3_rotatexyz(t_vector vec3, t_vector ovec3)
{
	t_vector rvec3;
	t_vector tmp_x;
	t_vector tmp_y;

	tmp_x = vec3_rotatex(vec3, ovec3.x);
	tmp_y = vec3_rotatey(tmp_x, ovec3.y);
	rvec3 = vec3_rotatez(tmp_y, ovec3.z);
	return (rvec3);
}

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
		* tan((cam.fov / 2) * (PI / 180));
	res.y = (1 - (2 * ((y + .5) / size_y))) * tan((cam.fov / 2) * (PI / 180));
	res.z = 1;
	return (new_ray(cam.pos, vec3_rotatexyz(res, cam.dir)));
}
