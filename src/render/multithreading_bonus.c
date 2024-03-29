/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:16:54 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/03 10:22:27 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#ifdef MULTITHREADING
# include <pthread.h>

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
	pthread_exit(NULL);
}

static void	*wait_thread_end(pthread_t *tid, long nproc, t_thread_data *thread)
{
	int	id;

	id = 0;
	while (id < nproc)
		pthread_join(tid[id++], NULL);
	free(tid);
	free(thread);
	return (NULL);
}

void	*render_scene_multithread(t_engine *engine, long nproc)
{
	pthread_t		*tid;
	t_thread_data	*thread;
	int				id;
	int				to;

	tid = malloc(nproc * sizeof(pthread_t));
	thread = malloc(nproc * sizeof(t_thread_data));
	if (!tid || !thread)
		close_minirt("error while processing engine threads");
	id = -1;
	to = -1;
	while (++id < nproc)
	{
		thread[id].from = to + 1;
		to = ft_min(engine->size_y - 1, thread[id].from
				+ (engine->size_y / nproc));
		thread[id].to = to;
		thread[id].engine = engine;
		thread[id].id = id;
		if (DEBUG)
			printf("thread id = %d (%d -> %d)\n", id, thread[id].from, to);
		if (pthread_create(&tid[id], NULL, (void *)render_thread, &thread[id]))
			close_minirt("unable to create thread");
	}
	return (wait_thread_end(tid, nproc, thread));
}

void	render(t_engine *engine)
{
	render_scene_multithread(engine, NPROCS);
	if (engine->save)
		return ;
	mlx_clear_window(engine->mlx, engine->window);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->frame->img, 0, 0);
	mlx_do_sync(engine->mlx);
	engine->need_render = false;
}

#endif
