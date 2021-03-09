/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:22:49 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/09 13:54:33 by gapoulai         ###   ########lyon.fr   */
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
	if (!engine->raw_file)
		close_minirt("empty scene");
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
	engine->scene.triangles = NULL;
	engine->scene.cylinders = NULL;
}

void	parse(char *line, t_engine *engine)
{
	if (is_id(line, "A"))
		add_alight(engine, line + 1);
	else if (is_id(line, "c"))
		add_camera(&engine->scene.cams, line + 1);
	else if (is_id(line, "sp"))
		add_sphere(&engine->scene.spheres, line + 2);
	else if (is_id(line, "l"))
		add_light(&engine->scene.lights, line + 1);
	else if (is_id(line, "pl"))
		add_plane(&engine->scene.planes, line + 2);
	else if (is_id(line, "sq"))
		add_square(&engine->scene.squares, line + 2);
	else if (is_id(line, "tr"))
		add_triangle(&engine->scene.triangles, line + 2);
	else if (is_id(line, "cy"))
		add_cylinder(&engine->scene.cylinders, line + 2);
	else if ((ft_strlen(line) == 1 && *line == '\n') || is_id(line, "R")
		|| DEBUG)
		;
	else
		close_minirt(ft_strjoin("invalid item in scene on line : '",
				ft_strjoin(line, "'")));
}

void	parse_scene(char **file, t_engine *engine)
{
	int		i;

	init_scene_parts(engine);
	i = -1;
	while (file[++i])
	{
		check_line(file[i]);
		parse(file[i], engine);
	}
}

void	get_file(t_engine *engine, const char *path)
{
	int		fd;

	fd = open((char *)path, O_DIRECTORY);
	if (fd != -1)
		close_minirt("scene must be a file");
	close(fd);
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
