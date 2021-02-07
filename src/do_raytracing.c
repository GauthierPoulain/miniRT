/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:28:33 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 16:48:13 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_hit	*closest_object(t_ray ray, t_scene *scene, void **object)
{
	t_hit *hit;

	if (!(hit = malloc(sizeof(t_hit))))
		close_minirt("failed to init hit storage value");
	hit->t = INFINITY;
	ray_spheres(ray, scene, hit, object);
	// ray_planes(ray, scene, hit, object);
	// ray_squares(ray, scene, hit, object);
	// ray_cylinders(ray, scene, hit, object);
	// ray_triangles(ray, scene, hit, object);
	return (hit);
}

double	distance(const t_vector p1, const t_vector p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) +
	pow(p2.z - p1.z, 2)));
}

t_rgb		*manage_light(t_engine *engine, t_scene *scene, t_hit *hit)
{
	t_list		*lights;
	t_light		*light;
	t_ray		to_light;
	void		*obstacle;
	t_hit		*hit_obstacle;
	t_rgb		diffuse;
	t_rgb		color_l;
	double		normal_dot_light;

	diffuse = creatergb(0, 0, 0);
	color_l = creatergb(0, 0, 0);
	lights = scene->lights;
	while (lights->next)
	{
		obstacle = NULL;
		light = (t_light *)(lights->content);
		to_light = new_ray(hit->pos, vectorminus(light->pos, hit->pos));
		hit_obstacle = closest_object(to_light, scene, &obstacle);
		if (hit_obstacle->t > distance(hit->pos, light->pos))
		{
			normal_dot_light = ft_max_double(dot(hit->normal,
			to_light.dir), 0.0) / (distance(hit->pos, light->pos)
			* (distance(hit->pos, light->pos)));
			color_l = add_rgb_rgb(mult_rgb_double(light->color,
			normal_dot_light), color_l);
			diffuse = mult_rgb_double(add_rgb_rgb(diffuse, color_l), ALBEDO);
			// vectoradd(to_light.dir, vectormutliply(hit->normal, -2. * normal_dot_light));
		}
		lights = lights->next;
	}
	hit->color = mult_rgb_rgb(add_rgb_rgb(mult_rgb_double(engine->alight.color, engine->alight.ratio), diffuse), hit->color);
	// hit->color = creatergb((fabsf(hit->normal.z)) * 255, (fabsf(hit->normal.x)) * 255, (fabsf(hit->normal.y)) * 255); // color en gradient en fonction de la normale a la surface
	// hit->color = creatergb((fabsf(hit->normal.z)) * 255, (fabsf(hit->normal.x)) * 255, (fabsf(hit->normal.y)) * 255); // color en gradient en fonction de la normale a la surface
	// hit->color = creatergb((fabsf(hit->pos.z)) * 255, (fabsf(hit->pos.x)) * 255, (fabsf(hit->pos.y)) * 255); // color en gradient en fonction de la position a la surface
	// hit->color = creatergb((fabsf(to_light.origin.z)) * 2, (fabsf(to_light.origin.x)) * 2, (fabsf(to_light.origin.y)) * 2); // color en gradient en fonction de la normale a la surface
	min_rgb(&hit->color);
	return (NULL);
}

void	do_raytracing(t_thread_data *thread, int x, int y)
{
	t_ray		ray;
	double		reflec;
	int			depth;
	void		*object;
	t_hit		*hit;

	reflec = 1;
	depth = 1;
	object = NULL;
	while (depth-- && reflec > EPSILON)
	{
		ray = init_ray(thread->engine, *thread->engine->cam, x, y);
		hit = closest_object(ray, &thread->engine->scene, &object);
		if (object)
		{
			if (dot(hit->normal, ray.dir) >= 0)
				hit->normal = vectormutliply(hit->normal, -1);
			manage_light(thread->engine, &thread->engine->scene, hit);
			set_pixel_color(thread->engine, x, y, ft_rgbtohex(
			hit->color.r, hit->color.g, hit->color.b));
		}
	}
}
