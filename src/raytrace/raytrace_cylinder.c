/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:05:39 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/03 16:11:49 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

typedef struct s_resole
{
	double		tmin;
	t_vector	t;
	t_vector	b;
	t_vector	normal;
}				t_resolve;

void	calc_things(double *a, double *b, t_ray ray, t_resolve *res)
{
	*a = dot(vectorcross(ray.dir, vectorminus(res->t, res->b)),
			vectorcross(ray.dir, vectorminus(res->t, res->b)));
	*b = 2 * dot(vectorcross(ray.dir, vectorminus(res->t, res->b)),
			vectorcross(vectorminus(ray.origin, res->b),
				vectorminus(res->t, res->b)));
}

void	infinite_cylinder(t_ray ray, t_cylinder cy, t_resolve *res)
{
	double		t;
	double		a;
	double		b;
	double		c;
	t_vector	p;

	calc_things(&a, &b, ray, res);
	c = calc_c_cy(ray, cy, res->t, res->b);
	if (pow(b, 2) - 4 * a * c > EPSILON)
	{
		t = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		if (t < EPSILON)
			t = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		p = vectoradd(ray.origin, vectormutliply(ray.dir, t));
		p = apply_rot(p, cy.dir, get_vector(0, 1, 0));
		res->b = apply_rot(res->b, cy.dir, get_vector(0, 1, 0));
		res->t = apply_rot(res->t, cy.dir, get_vector(0, 1, 0));
		if (t < res->tmin && p.y >= res->b.y && p.y <= res->t.y)
		{
			res->tmin = t;
			p = vectoradd(ray.origin, vectormutliply(ray.dir, t));
			res->normal = calclanormaleparceqttroplongue(cy, p);
		}
		else if (p.y >= res->b.y && p.y <= res->t.y)
		{
			res->tmin = t;
			p = vectoradd(ray.origin, vectormutliply(ray.dir, t));
			res->normal = calclanormaleparceqttroplongue(cy, p);
		}
	}
}

void	check_caps(t_ray ray, t_resolve *res, t_cylinder cy)
{
	double		t;
	t_vector	pos;

	t = intersect_caps_cy(ray, cy, res->t);
	pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
	if (t > EPSILON && distance(pos, res->t) < cy.radius)
	{
		res->tmin = t;
		res->normal = process_normal_cy(ray, cy.dir);
	}
	t = intersect_caps_cy(ray, cy, res->b);
	pos = vectoradd(ray.origin, vectormutliply(ray.dir, t));
	if (t > EPSILON && distance(pos, res->b) < cy.radius)
	{
		res->tmin = t;
		res->normal = process_normal_cy(ray, cy.dir);
	}
}

bool	intersect_cylinder(t_ray ray, t_cylinder cy, t_hit *hit)
{
	t_resolve	res;

	if (cy.height < EPSILON || cy.radius < EPSILON)
		return (false);
	res.tmin = INFINITY;
	res.b = vectorminus(cy.pos, vectormutliply(cy.dir, cy.height / 2));
	res.t = vectoradd(cy.pos, vectormutliply(cy.dir, cy.height / 2));
	// if (CY_CAPS)
		check_caps(ray, &res, cy);
	infinite_cylinder(ray, cy, &res);
	if (res.tmin < EPSILON || res.tmin == INFINITY || res.tmin > hit->t)
		return (false);
	hit->t = res.tmin;
	hit->pos = vectoradd(ray.origin, vectormutliply(ray.dir, res.tmin));
	hit->normal = get_normalize(res.normal);
	return (true);
}

void	raytrace_cylinder(t_ray ray, t_scene *scene, t_hit *hit, void **obj)
{
	t_list		*item;
	t_cylinder	*cylinder;

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
