/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:29:58 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 15:13:19 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	key_event(int key, t_engine *engine)
{
	if (DEBUG)
		printf("key press = %d\n", key);
	if (key == KEY_EXIT)
		close_minirt(NULL);
	engine->need_render = true;
	return (0);
}

int	close_event(void)
{
	close_minirt(NULL);
	return (0);
}

int	loop_event(t_engine *engine)
{
	if (engine->need_render)
		render(engine);
	return (0);
}

void	engine_event(t_engine *engine)
{
	mlx_key_hook(engine->window, *key_event, engine);
	mlx_hook(engine->window, 17, 0, *close_event, NULL);
	mlx_loop_hook(engine->mlx, *loop_event, engine);
}
