/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:00:06 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:54:02 by gapoulai         ###   ########lyon.fr   */
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

double	distance(t_vector p1, t_vector p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)
			+ pow(p2.z - p1.z, 2)));
}
