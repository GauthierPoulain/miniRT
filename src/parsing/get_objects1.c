/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:19:28 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:10:47 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	add_alight(t_engine *engine, char *file)
{
	t_alight	light;

	light.ratio = ft_atof(file);
	file += ft_atof_len(file);
	light.color = get_rgb(&file);
	if (light.ratio < 0 || light.ratio > 1)
		close_minirt("ambient light ratio is out of range [0.0, 1.0]");
	engine->alight = light;
}

void	add_camera(t_list **lst, char *file)
{
	t_cam		*cam;
	t_list		*new;
	static int	id;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		close_minirt("error while parsing the scene");
	cam->pos = parse_vector(&file);
	cam->dir = parse_vector(&file);
	cam->fov = ft_atoi(file);
	cam->id = ++id;
	if (!vector_limit(cam->dir, -1, 1))
		close_minirt("camera rotation is out of range [-1, 1]");
	if (!ft_isinrange(cam->fov, 0, 180))
		close_minirt("cmaera fov is out of range [0, 180]");
	new = ft_lstnew(cam);
	if (!new)
		close_minirt("error while parsing the scene");
	ft_lstadd_back(lst, new);
}

void	add_sphere(t_list **lst, char *file)
{
	t_sphere	*sp;
	t_list		*new;

	sp = malloc(sizeof(t_sphere));
	if (!sp)
		close_minirt("error while parsing the scene");
	sp->pos = parse_vector(&file);
	sp->diameter = ft_atof(file) / 2;
	file += ft_atof_len(file);
	sp->color = get_rgb(&file);
	new = ft_lstnew(sp);
	if (!new)
		close_minirt("error while parsing the scene");
	ft_lstadd_back(lst, new);
}

void	add_light(t_list **lst, char *file)
{
	t_light	*light;
	t_list	*new;

	light = malloc(sizeof(t_light));
	if (!light)
		close_minirt("error while parsing the scene");
	light->pos = parse_vector(&file);
	light->brightness = ft_atof(file);
	file += ft_atof_len(file);
	light->color = get_rgb(&file);
	if (light->brightness < 0 || light->brightness > 1)
		close_minirt("light brightness is out of range [0.0, 1.0]");
	new = ft_lstnew(light);
	if (!new)
		close_minirt("error while parsing the scene");
	ft_lstadd_back(lst, new);
}

void	add_plane(t_list **lst, char *file)
{
	t_plane	*plane;
	t_list	*new;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		close_minirt("error while parsing the scene");
	plane->origin = parse_vector(&file);
	plane->normal = parse_vector(&file);
	if (!vector_limit(plane->normal, -1, 1))
		close_minirt("plane normal is out of range [-1.0, 1.0]");
	plane->normal.x = to_rad(90 * plane->normal.x);
	plane->normal.y = to_rad(90 * plane->normal.y);
	plane->normal.z = to_rad(90 * plane->normal.z);
	set_normalize(&plane->normal);
	plane->color = get_rgb(&file);
	new = ft_lstnew(plane);
	if (!new)
		close_minirt("error while parsing the scene");
	ft_lstadd_back(lst, new);
}
