/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:22:49 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/22 12:31:02 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	check_scene(t_engine *engine)
{
	int			alight;
	int			resolution;
	int			i;

	alight = 0;
	resolution = 0;
	i = -1;
	while (engine->raw_file[++i])
	{
		if (is_id(engine->raw_file[i], "A"))
			alight++;
		if (is_id(engine->raw_file[i], "R"))
			resolution++;
	}
	if (!resolution)
		close_minirt("missing resolution in scene");
	if (resolution > 1)
		close_minirt("too much resolutions settings in scene");
	if (!alight)
		add_alight(engine, "0 0,0,0");
	if (alight > 1)
		close_minirt("too much ambient light in scene");
}

void	init_scene_parts(t_engine *engine)
{
	engine->scene.cams = NULL;
	engine->scene.lights = NULL;
	engine->scene.planes = NULL;
	engine->scene.spheres = NULL;
	engine->scene.squares = NULL;
	engine->scene.disks = NULL;
	engine->scene.triangles = NULL;
	engine->scene.cylinders = NULL;
}

void	parse_scene(char **file, t_engine *engine)
{
	int		i;

	init_scene_parts(engine);
	i = -1;
	while (file[++i])
	{
		if (is_id(file[i], "A"))
			add_alight(engine, file[i] + 1);
		else if (is_id(file[i], "c"))
			add_camera(&engine->scene.cams, file[i] + 1);
		else if (is_id(file[i], "sp"))
			add_sphere(&engine->scene.spheres, file[i] + 2);
		else if (is_id(file[i], "l"))
			add_light(&engine->scene.lights, file[i] + 1);
		else if (is_id(file[i], "pl"))
			add_plane(&engine->scene.planes, file[i] + 2);
		else if (is_id(file[i], "sq"))
			add_square(&engine->scene.squares, file[i] + 2);
		else if (is_id(file[i], "ds"))
			add_disk(&engine->scene.disks, file[i] + 2);
		else if (is_id(file[i], "tr"))
			add_triangle(&engine->scene.triangles, file[i] + 2);
		else if (is_id(file[i], "cy"))
			add_cylinder(&engine->scene.cylinders, file[i] + 2);
	}
}

void	get_file(t_engine *engine, const char *path)
{
	int		fd;

	if (open((char *)path, O_DIRECTORY) != -1)
		close_minirt("scene must be a file");
	fd = open((char *)path, O_RDONLY);
	if (fd == -1)
		close_minirt("file not found");
	if (!ft_endwith((char *)path, ".rt"))
		close_minirt("invalid file format");
	engine->raw_file = ft_read_file(fd);
	close(fd);
	check_scene(engine);
	parse_scene(engine->raw_file, engine);
}
