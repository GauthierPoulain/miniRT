/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:05:39 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/18 08:10:33 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	process_normal(t_ray ray, t_vector normal)
{
	if (dot(ray.dir, normal) < 0)
		return (normal);
	return (vectormutliply(normal, -1));
}

double	intersect_caps(t_ray ray, t_cylinder cy, t_vector pos)
{
	t_vector	tmp;
	double		a;
	double		b;
	double		t;

	t = 0;
	tmp = vectorminus(ray.origin, pos);
	a = dot(tmp, cy.dir);
	b = dot(ray.dir, cy.dir);
	if (!(b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0)))
		t = -a / b;
	return(t);
}

double	calc_c(t_ray ray, t_cylinder cy, t_vector t, t_vector b)
{
	return (dot(vectorcross(vectorminus(ray.origin, b), vectorminus(t, b)), vectorcross(vectorminus(ray.origin, b), vectorminus(t, b)))
			- (cy.radius * cy.radius * dot(vectorminus(t, b), vectorminus(t, b))));
}

void	infinite_cylinder(t_ray ray, t_cylinder cy, t_vector *t1, t_vector *b1, double *tmin)
{
	double		t;
	double		a;
	double		b;
	double		c;
	t_vector	p;
	t_vector	normal;

	a = dot(vectorcross(ray.dir, vectorminus(*t1, *b1)), vectorcross(ray.dir, vectorminus(*t1, *b1)));
	b = 2 * dot(vectorcross(ray.dir, vectorminus(*t1, *b1)), vectorcross(vectorminus(ray.origin, *b1), vectorminus(*t1, *b1)));
	c = calc_c(ray, cy, *t1, *b1);
	if (pow(b, 2) - 4 * a * c > 0)
	{
		t = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		if (t < 0)
			t = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		p = vectoradd(ray.origin, vectormutliply(ray.dir, t));
		p = apply_rot(p, cy.dir, get_vector(0, 1, 0));
		*b1 = apply_rot(*b1, cy.dir, get_vector(0, 1, 0));
		*t1 = apply_rot(*t1, cy.dir, get_vector(0, 1, 0));
		if (t < *tmin && p.y >= b1->y && p.y <= t1->y && (*tmin = t))
		{
			p = apply_rot(p, get_vector(0, 1, 0), cy.dir);
			normal = get_normalize(vectorminus(p, cy.pos));
		}
	}
}

bool	intersect_cylinder(t_ray ray, t_cylinder cy, t_hit *hit)
{
	double		t;
	double		tmin;
	t_vector	b;
	t_vector	v;
	t_vector	pos;
	t_vector	normal;

	t = 0;
	tmin = INFINITY;
	b = vectorminus(cy.pos, vectormutliply(get_normalize(cy.dir), cy.height / 2));
	v = vectoradd(cy.pos, vectormutliply(get_normalize(cy.dir), cy.height / 2));
	t = intersect_caps(ray, cy, v);
	pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
	if (t > 0 && distance(pos, b) <= cy.radius && (tmin = t))
		normal = process_normal(ray, cy.dir);
	infinite_cylinder(ray, cy, &v, &b, &tmin);
	if (!(tmin > 0 && tmin != INFINITY) || tmin > hit->t)
		return (false);
	hit->t = tmin;
	hit->pos = pos;
	hit->normal = normal;
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
