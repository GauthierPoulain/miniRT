/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:28:33 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/09 15:52:19 by gapoulai         ###   ########lyon.fr   */
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
	hit->color = creatergb(0, 0, 0);
	raytrace_spheres(ray, scene, hit, object);
	raytrace_planes(ray, scene, hit, object);
	raytrace_square(ray, scene, hit, object);
	raytrace_disk(ray, scene, hit, object);
	return (hit);
}

void	process_light(t_light_managment *data, t_hit *hit, t_scene *scene)
{
	data->color_l = creatergb(0, 0, 0);
	data->obstacle = NULL;
	data->light = data->lights->content;
	data->to_light = new_ray(hit->pos, vectorminus(data->light->pos, hit->pos));
	data->hit_obstacle = closest_object(data->to_light, scene, &data->obstacle);
	if (distance(hit->pos, data->light->pos) < data->hit_obstacle->t)
	{
		data->normal_dot_light = ft_dmax(dot(hit->normal,
					data->to_light.dir), 0) * LIGHT_MULT
			/ distance(hit->pos, data->light->pos);
		data->color_l = mult_rgb_double(add_rgb_rgb(mult_rgb_double(
						data->light->color,
						data->normal_dot_light), data->color_l), ALBEDO
				* data->light->brightness);
		data->diffuse = add_rgb_rgb(data->diffuse, data->color_l);
	}
	free(data->hit_obstacle);
	data->lights = data->lights->next;
}

t_rgb	*manage_light(t_thread_data *thread, t_scene *scene, t_hit *hit)
{
	t_light_managment	data;

	data.diffuse = creatergb(0, 0, 0);
	data.lights = scene->lights;
	while (data.lights)
		process_light(&data, hit, scene);
	hit->color = mult_rgb_rgb(add_rgb_rgb(mult_rgb_double(
					thread->engine->alight.color, thread->engine->alight.ratio),
				data.diffuse), hit->color);
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
	}
	free(hit);
	if (hit->color.r == 255 && hit->color.g == 255 && hit->color.b == 255)
	{
		printf("x = %d, y = %d\n", x, y);
	}
	set_pixel_color(thread->engine, x, y, ft_rgbtohex(
		hit->color.r, hit->color.g, hit->color.b));
}
