/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:05:39 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/08 11:17:45 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

typedef struct s_inf
{
	double		t;
	double		a;
	double		b;
	double		c;
	t_vector	p;
}				t_inf;

void	calc_things(double *a, double *b, t_ray ray, t_cyresolve *res)
{
	*a = dot(vectorcross(ray.dir, vectorminus(res->t, res->b)),
			vectorcross(ray.dir, vectorminus(res->t, res->b)));
	*b = 2 * dot(vectorcross(ray.dir, vectorminus(res->t, res->b)),
			vectorcross(vectorminus(ray.origin, res->b),
				vectorminus(res->t, res->b)));
}

void	inf_cylinder_part2(t_inf inf, t_ray ray, t_cyresolve *res, t_cylinder
			cy)
{
	inf.t = (-inf.b + sqrt(pow(inf.b, 2) - 4 * inf.a * inf.c))
		/ (2 * inf.a);
	inf.p = vectoradd(ray.origin, vectormutliply(ray.dir, inf.t));
	inf.p = apply_rot(inf.p, cy.dir, get_vector(0, 1, 0));
	if (inf.t < res->tmin && inf.p.y >= res->b.y && inf.p.y <= res->t.y)
	{
		res->tmin = inf.t;
		inf.p = vectoradd(ray.origin, vectormutliply(ray.dir, inf.t));
		res->normal = calclanormalparceqttroplongue(cy, inf.p);
	}
}

void	infinite_cylinder(t_ray ray, t_cylinder cy, t_cyresolve *res)
{
	t_inf	inf;

	calc_things(&inf.a, &inf.b, ray, res);
	inf.c = calc_c_cy(ray, cy, res->t, res->b);
	if (pow(inf.b, 2) - 4 * inf.a * inf.c > EPSILON)
	{
		inf.t = (-inf.b - sqrt(pow(inf.b, 2) - 4 * inf.a * inf.c))
			/ (2 * inf.a);
		if (inf.t < EPSILON)
			inf.t = (-inf.b + sqrt(pow(inf.b, 2) - 4 * inf.a * inf.c))
				/ (2 * inf.a);
		inf.p = vectoradd(ray.origin, vectormutliply(ray.dir, inf.t));
		inf.p = apply_rot(inf.p, cy.dir, get_vector(0, 1, 0));
		res->b = apply_rot(res->b, cy.dir, get_vector(0, 1, 0));
		res->t = apply_rot(res->t, cy.dir, get_vector(0, 1, 0));
		if (inf.t < res->tmin && inf.p.y >= res->b.y && inf.p.y <= res->t.y)
		{
			res->tmin = inf.t;
			inf.p = vectoradd(ray.origin, vectormutliply(ray.dir, inf.t));
			res->normal = calclanormalparceqttroplongue(cy, inf.p);
		}
		if (!CY_CAPS)
			inf_cylinder_part2(inf, ray, res, cy);
	}
}

bool	intersect_cylinder(t_ray ray, t_cylinder cy, t_hit *hit)
{
	t_cyresolve	res;

	if (cy.height < EPSILON || cy.radius < EPSILON)
		return (false);
	res.tmin = INFINITY;
	res.b = vectorminus(cy.pos, vectormutliply(cy.dir, cy.height / 2));
	res.t = vectoradd(cy.pos, vectormutliply(cy.dir, cy.height / 2));
	if (CY_CAPS)
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
