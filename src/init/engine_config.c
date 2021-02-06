/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:06:05 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 09:26:01 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_engine	*init_engine(void)
{
	t_engine	*engine;

	engine = malloc(sizeof(t_engine));
	if (!engine)
		close_minirt("(malloc error) unable to create engine");
	engine->mlx = mlx_init();
	if (!engine->mlx)
		close_minirt("failed to init mlx engine");
	engine->cam = NULL;
	engine->need_render = true;
	engine->save = false;
	return (engine);
}
