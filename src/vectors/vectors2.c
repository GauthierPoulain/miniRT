/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:46:20 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 11:51:05 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double		dot(t_vector s1, t_vector s2)
{
	return (s1.x * s2.x + s1.y * s2.y + s1.z * s2.z);
}

double		sqnorm(t_vector vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

void		set_normalize(t_vector *vec)
{
	double		norm;

	norm = sqrt(sqnorm(*vec));
	vec->x /= norm;
	vec->y /= norm;
	vec->z /= norm;
}

t_vector	get_normalize(t_vector vec)
{
	double		norm;
	t_vector	res;

	norm = sqrt(sqnorm(vec));
	res.x = vec.x / norm;
	res.y = vec.y / norm;
	res.z = vec.z / norm;
	return (res);
}

bool		vector_limit(t_vector vec, double min, double max)
{
	if (vec.x < min || vec.y < min || vec.z < min)
		return (false);
	else if (vec.x > max || vec.y > max || vec.z > max)
		return (false);
	else
		return (true);
}
