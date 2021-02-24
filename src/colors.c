/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:40:52 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/24 14:37:22 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb	creatergb(int r, int g, int b)
{
	t_rgb	new;

	new.r = r;
	new.b = b;
	new.g = g;
	return (new);
}

t_rgb	mult_rgb_rgb(t_rgb rgb, t_rgb mult)
{
	return (creatergb(rgb.r * (mult.r / 255.), rgb.g
			* (mult.g / 255.), rgb.b * (mult.b / 255.)));
}

t_rgb	mult_rgb_double(t_rgb rgb, double mult)
{
	return (creatergb((double)rgb.r * mult, (double)rgb.g * mult, (double)rgb.b * mult));
}

t_rgb	add_rgb_rgb(t_rgb rgb, t_rgb add)
{
	return (creatergb(rgb.r + add.r, rgb.g + add.g, rgb.b + add.b));
}

void	min_rgb(t_rgb *color)
{
	color->r = ft_min(color->r, 255);
	color->g = ft_min(color->g, 255);
	color->b = ft_min(color->b, 255);
}
