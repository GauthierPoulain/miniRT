/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:18:33 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/15 08:37:17 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	intersect_square(t_ray ray, t_square square, t_hit *hit)
{
	(void)ray;
	(void)square;
	(void)hit;
	return (false);
}

void	raytrace_square(t_ray ray, t_scene *scene, t_hit *hit, void **obj)
{
	t_list		*item;
	t_square	*square;

	item = scene->squares;
	while (item)
	{
		square = item->content;
		if (intersect_square(ray, *square, hit))
		{
			*obj = square;
			hit->color = square->color;
		}
		item = item->next;
	}
}
