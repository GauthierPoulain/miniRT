/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_multithreads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:41:20 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 15:34:47 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus.h"

void		*render_thread(t_thread_data *thread)
{
	int			x;
	int			y;

	y = thread->from - 1;
	while (++y <= thread->to)
	{
		x = -1;
		while (++x < thread->engine->size_x)
		{
			// printf("x = %d, y = %d\n", x, y);
			thread->ray = init_ray(thread->engine, *thread->engine->cam, x, y);
			set_pixel_color(thread->engine, x, y, ft_rgbtohex(0, 0, 0));
			do_raytracing(thread, x, y);
		}
	}
	if (DEBUG)
		printf("thread %d done\n", thread->id);
	pthread_exit(NULL);
}

void		*render_scene_multithread(t_engine *engine, long nproc)
{
	pthread_t		tid[nproc];
	t_thread_data	thread[nproc];
	int				id;
	int				to;

	setbuf(stdout, NULL);
	id = 0;
	to = -1;
	while (id < nproc)
	{
		thread[id].from = to + 1;
		to = ft_math_min(engine->size_y - 1, thread[id].from +
		(engine->size_y / nproc));
		thread[id].to = to;
		thread[id].engine = engine;
		thread[id].id = id;
		if (DEBUG)
			printf("thread id = %d (%d -> %d)\n", id, thread[id].from, to);
		if (!pthread_create(&tid[id], NULL, (void *)render_thread, &thread[id]))
			id++;
	}
	id = 0;
	while (id < nproc)
		pthread_join(tid[id++], NULL);
	return (NULL);
}

void		render(t_engine *engine)
{
	render_scene_multithread(engine, sysconf(_SC_NPROCESSORS_ONLN));
	printf("render\n");
	if (engine->save)
		return ;
	mlx_clear_window(engine->mlx, engine->window);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->frame->img, 0, 0);
	mlx_do_sync(engine->mlx);
	printf("render done\n");
	engine->need_render = false;
}
