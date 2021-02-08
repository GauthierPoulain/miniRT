/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:28:33 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 15:13:05 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_hit	*closest_object(t_ray ray, t_scene *scene, void **object)
{
	t_hit	*hit;

	hit = malloc(sizeof(t_hit));
	if (!hit)
		close_minirt("failed to init hit storage value");
	hit->t = INFINITY;
	raytrace_spheres(ray, scene, hit, object);
	raytrace_planes(ray, scene, hit, object);
	return (hit);
}

t_rgb	*manage_light(t_thread_data *thread, t_scene *scene, t_hit *hit)
{
	t_list	*lights;
	t_light	*light;
	t_ray	to_light;
	void	*obstacle;
	t_hit	*hit_obstacle;
	t_rgb	diffuse;
	t_rgb	color_l;
	double	normal_dot_light;

	diffuse = creatergb(0, 0, 0);
	lights = scene->lights;
	while (lights)
	{
		color_l = creatergb(0, 0, 0);
		obstacle = NULL;
		light = lights->content;
		to_light = new_ray(hit->pos, vectorminus(light->pos, hit->pos));
		hit_obstacle = closest_object(to_light, scene, &obstacle);
		if (distance(hit->pos, light->pos) < hit_obstacle->t)
		{
			normal_dot_light = ft_dmax(dot(hit->normal,
						to_light.dir), 0) * LIGHT_MULT
				/ distance(hit->pos, light->pos);
			color_l = mult_rgb_double(add_rgb_rgb(mult_rgb_double(light->color,
							normal_dot_light), color_l), ALBEDO
					* light->brightness);
			diffuse = add_rgb_rgb(diffuse, color_l);
		}
		free(hit_obstacle);
		lights = lights->next;
	}
	hit->color = mult_rgb_rgb(add_rgb_rgb(mult_rgb_double(
					thread->engine->alight.color, thread->engine->alight.ratio),
				diffuse), hit->color);
	min_rgb(&hit->color);
	return (NULL);
}

void	do_raytracing(t_thread_data *thread, int x, int y)
{
	t_ray	ray;
	void	*object;
	t_hit	*hit;

	object = NULL;
	ray = init_ray(thread->engine, *thread->engine->cam, x, y);
	hit = closest_object(ray, &thread->engine->scene, &object);
	if (object)
	{
		if (dot(hit->normal, ray.dir) >= 0)
			hit->normal = vectormutliply(hit->normal, -1);
		manage_light(thread, &thread->engine->scene, hit);
		set_pixel_color(thread->engine, x, y, ft_rgbtohex(
		hit->color.r, hit->color.g, hit->color.b));
	}
	free(hit);
}
