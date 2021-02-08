/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:06:05 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:56:06 by gapoulai         ###   ########lyon.fr   */
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

int	get_resolution(char **str)
{
	int		res;

	res = ft_atoi(*str);
	*str += ft_atoi_len(*str);
	return (res);
}

void	get_win_size(t_engine *engine, int save)
{
	char	*res_line;
	int		tmpx;
	int		tmpy;

	res_line = ft_get_line(engine->raw_file, "R", "") + 1;
	tmpx = get_resolution(&res_line);
	tmpy = get_resolution(&res_line);
	if (save)
	{
		engine->size_x = tmpx;
		engine->size_y = tmpy;
	}
	else
	{
		mlx_get_screen_size(engine->mlx, &engine->size_x, &engine->size_y);
		engine->size_x = ft_min(tmpx, engine->size_x);
		engine->size_y = ft_min(tmpy, engine->size_y);
	}
	if (engine->size_x < 0 || engine->size_x > 16384
		|| engine->size_y < 0 || engine->size_y > 16384)
		close_minirt("invalid fame size, must be between 0 and 16384");
}

void	init_window(t_engine *engine)
{
	engine->window = mlx_new_window(engine->mlx, engine->size_x,
			engine->size_y, "miniRT by G@PoUl@i_Le_BoSs");
}
