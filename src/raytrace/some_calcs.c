/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_calcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:48:13 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:54:36 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	secdegsolve(t_vector point, double *t1, double *t2)
{
	double	discr;
	double	root;

	discr = point.y * point.y - 4 * point.x * point.z;
	if (discr < 0)
		return (false);
	else if (discr == 0)
	{
		*t1 = -0.5 * point.y / point.x;
		*t2 = -0.5 * point.y / point.x;
	}
	else
	{
		if (point.y > 0)
			root = -0.5 * (point.y + sqrt(discr));
		else
			root = -0.5 * (point.y - sqrt(discr));
		*t1 = root / point.x;
		*t2 = point.z / root;
	}
	if (*t1 > *t2)
		ft_swap(t1, t2);
	return (true);
}
