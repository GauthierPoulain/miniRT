/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monothread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:17:07 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/25 10:31:54 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS
# include "../../includes/minirt.h"

void	*render_thread(t_thread_data *thread)
{
	int			x;
	int			y;

	y = thread->from - 1;
	while (++y <= thread->to)
	{
		x = -1;
		while (++x < thread->engine->size_x)
		{
			set_pixel_color(thread->engine, x, y, ft_rgbtohex(0, 0, 0));
			do_raytracing(thread, x, y);
		}
	}
	if (DEBUG)
		printf("thread %d done\n", thread->id);
	return (NULL);
}

void	*render_scene(t_engine *engine)
{
	t_thread_data	thread;

	thread.from = 0;
	thread.to = engine->size_y - 1;
	thread.engine = engine;
	thread.id = -1;
	render_thread(&thread);
	return (NULL);
}

void	render(t_engine *engine)
{
	render_scene(engine);
	if (engine->save)
		return ;
	mlx_clear_window(engine->mlx, engine->window);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->frame->img, 0, 0);
	mlx_do_sync(engine->mlx);
	engine->need_render = false;
}
#endif