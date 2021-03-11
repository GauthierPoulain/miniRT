/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 07:53:02 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/11 10:17:46 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	check_args(int argc, const char **argv)
{
	if (argc <= 1 || argc >= 4)
		close_minirt("wrong call, must be : ./miniRT <scene>.rt (--save)");
	else if (!ft_endwith((char *)argv[1], ".rt"))
		close_minirt("invalid scene format");
	else if (argc == 3 && ft_strcmp((char *)argv[2], "--save"))
		close_minirt("second argument must be '--save'");
}

int	main(int argc, char const **argv)
{
	t_engine	*engine;

	check_args(argc, argv);
	engine = init_engine();
	get_file(engine, argv[1]);
	if (argc == 3 && !ft_strcmp((char *)argv[2], "--save"))
		engine->save = true;
	get_win_size(engine, engine->save);
	init_frame(engine);
	change_camera(engine);
	if (engine->save)
	{
		get_save(engine, "save.bmp");
		close_minirt(NULL);
	}
	init_window(engine);
	engine_event(engine);
	mlx_loop(engine->mlx);
	close_minirt("unhandled error in mlx loop :/");
	return (0);
}
