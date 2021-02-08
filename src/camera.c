/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:25:50 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 15:07:52 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	change_camera(t_engine *engine)
{
	t_list	*item;

	item = engine->scene.cams;
	while (item)
	{
		if (!engine->cam || ((t_cam *)(item->content))->id > engine->cam->id)
		{
			engine->cam = item->content;
			return ;
		}
		item = item->next;
	}
	if (engine->cam)
	{
		engine->cam = NULL;
		change_camera(engine);
	}
	else
		close_minirt("missing camera in scene");
}
