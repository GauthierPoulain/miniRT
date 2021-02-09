/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:55:29 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/09 15:32:56 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb	moy_rgb_rgb(t_rgb rgb1, t_rgb rgb2)
{
	return (creatergb((rgb1.r + rgb2.r) / 2, (rgb1.g + rgb2.g)
			/ 2, (rgb1.b + rgb2.b) / 2));
}
