/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:00:06 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 16:11:13 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	mult_mat(double mat[3][3], t_vector vect)
{
	double		x;
	double		y;
	double		z;
	t_vector	res;

	x = mat[0][0] * vect.x + mat[0][1] * vect.x + mat[0][2] * vect.x;
	y = mat[1][0] * vect.y + mat[1][1] * vect.y + mat[1][2] * vect.y;
	z = mat[2][0] * vect.z + mat[2][1] * vect.z + mat[2][2] * vect.z;
	res = get_vector(x, y, z);
	return (res);
}

t_vector	rot_vect(t_vector vect, double angle, char axe)
{
	double	alpha;

	alpha = to_rad(angle * 0.5);
	if (axe == 'x')
		return (mult_mat((double[3][3])
	{ {1, 0, 0}, { 0, cos(alpha),
-sin(alpha) }, { 0, sin(alpha), -cos(alpha) }
	}, vect));
	else if (axe == 'y')
		return (mult_mat((double[3][3])
		{ {cos(alpha), 0, sin(alpha)}, { 0, 1, 0 },
		{ -sin(alpha), 0, cos(alpha) } }, vect));
	else if (axe == 'z')
		return (mult_mat((double[3][3])
		{ {cos(alpha), sin(alpha), 0},
		{ sin(alpha), cos(alpha), 0 }, { 0, 0, 1 } }, vect));
	else
		return (get_vector(0, 0, 0));
}
