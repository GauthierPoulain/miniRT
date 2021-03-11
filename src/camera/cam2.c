/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:26:05 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/11 13:28:23 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vec3_rotatex(t_vector vec3, double alpha)
{
	double	y;
	double	z;

	y = vec3.y * cos(PI * alpha) - vec3.z * sin(PI * alpha);
	z = vec3.y * sin(PI * alpha) + vec3.z * cos(PI * alpha);
	return (get_vector(vec3.x, y, z));
}

t_vector	vec3_rotatey(t_vector vec3, double beta)
{
	double	x;
	double	z;

	x = vec3.x * cos(PI * beta) + vec3.z * sin(PI * beta);
	z = vec3.x * -sin(PI * beta) + vec3.z * cos(PI * beta);
	return (get_vector(x, vec3.y, z));
}

t_vector	vec3_rotatez(t_vector vec3, double gamma)
{
	double	x;
	double	y;

	x = vec3.x * cos(PI * gamma) - vec3.y * sin(PI * gamma);
	y = vec3.x * sin(PI * gamma) + vec3.y * cos(PI * gamma);
	return (get_vector(x, y, vec3.z));
}

t_vector	vec3_rotatexyz(t_vector vec3, t_vector ovec3)
{
	t_vector	rvec3;
	t_vector	tmp_x;
	t_vector	tmp_y;

	tmp_x = vec3_rotatex(vec3, ovec3.x);
	tmp_y = vec3_rotatey(tmp_x, ovec3.y);
	rvec3 = vec3_rotatez(tmp_y, ovec3.z);
	return (rvec3);
}
