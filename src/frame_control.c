/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:23:04 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 12:25:27 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		set_pixel_color(t_engine *engine, int x, int y, int color)
{
	char *dst;

	dst = engine->frame->addr + (y *
		(engine->frame->line_len) + x * (engine->frame->bpp / 8));
	*(unsigned int *)dst = color;
}

t_rgb		get_pixel_color(t_engine *engine, int x, int y)
{
	char	*src;
	t_rgb	rgb;

	src = engine->frame->addr + (y *
		(engine->frame->line_len) + x * (engine->frame->bpp / 8));
	rgb.r = (unsigned int)src[0];
	rgb.g = (unsigned int)src[1];
	rgb.b = (unsigned int)src[2];
	return (rgb);
}

void		init_frame(t_engine *engine)
{
	engine->frame = malloc(sizeof(t_frame));
	if (!engine->frame)
		close_minirt("Unable to init frame");
	engine->frame->img = mlx_new_image(engine->mlx, engine->size_x,
		engine->size_y);
	if (engine->frame->img)
		engine->frame->addr = mlx_get_data_addr(engine->frame->img,
			&engine->frame->bpp, &engine->frame->line_len,
			&engine->frame->endian);
	if (!engine->frame->img || !engine->frame->addr)
		close_minirt("Unable to init frame");
}
