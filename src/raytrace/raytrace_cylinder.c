/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:05:39 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/18 12:33:32 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	cy_normal(t_hit *hit, const t_cylinder cy)
{
	t_vector	c0;
	t_vector	v;

	if (hit->pos.x < cy.pos.x + cy.radius && hit->pos.x > cy.pos.x - cy.radius
		&& hit->pos.z < cy.pos.z + cy.radius && hit->pos.z > cy.pos.z - cy.radius)
	{
		if (hit->pos.y < cy.pos.y + cy.height
			&& hit->pos.y > cy.pos.y + cy.height)
			return (get_vector(0, 1, 0));
		if (hit->pos.y < cy.pos.y && hit->pos.y > cy.pos.y)
			return (get_vector(0, -1, 0));
	}
	c0 = get_vector(cy.pos.x, hit->pos.y, cy.pos.z);
	v = vectorminus(hit->pos, c0);
	return (get_normalize(v));
}

bool	intersect_cylinder(t_ray ray, t_cylinder cy, t_hit *hit)
{
	t_vector	p0;
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t;

	p0 = get_vector(ray.origin.x - cy.pos.x,
		ray.origin.y - cy.pos.y, ray.origin.z - cy.pos.z);
	a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	b = ray.dir.x * p0.x + ray.dir.z * p0.z;
	c = p0.x * p0.x + p0.z * p0.z - cy.radius * cy.radius;
	delta = b * b - a * c;
	if (delta < EPSILON)
		return (false);
	t = (-b - sqrt(delta)) / a;
	printf("c = %f\n", c);
	if (t < EPSILON || t > hit->t)
		return (false);
	hit->t = t;
	hit->pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
	hit->normal = cy_normal(hit, cy);
	return (true);
}

void	raytrace_cylinder(t_ray ray, t_scene *scene, t_hit *hit, void **obj)
{
	t_list *item;
	t_cylinder *cylinder;

	item = scene->cylinders;
	while (item)
	{
		cylinder = item->content;
		if (intersect_cylinder(ray, *cylinder, hit))
		{
			*obj = cylinder;
			hit->color = cylinder->color;
		}
		item = item->next;
	}
}
