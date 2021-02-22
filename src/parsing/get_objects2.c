/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:16:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/22 09:37:11 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	add_square(t_list **lst, char *file)
{
	t_square	*square;
	t_list		*new;

	square = malloc(sizeof(t_square));
	if (!square)
		close_minirt("error while parsing the scene");
	square->origin = parse_vector(&file);
	square->normal = parse_vector(&file);
	if (!vector_limit(square->normal, -1, 1))
		close_minirt("square orientation is out of range [-1.0, 1.0]");
	square->normal.x = to_rad(90 * square->normal.x);
	square->normal.y = to_rad(90 * square->normal.y);
	square->normal.z = to_rad(90 * square->normal.z);
	set_normalize(&square->normal);
	square->size = ft_atof(file);
	file += ft_atof_len(file);
	square->color = get_rgb(&file);
	new = ft_lstnew(square);
	if (!new)
		close_minirt("error while parsing the scene");
	ft_lstadd_back(lst, new);
}

void	add_disk(t_list **lst, char *file)
{
	t_disk	*disk;
	t_list	*new;

	disk = malloc(sizeof(t_disk));
	if (!disk)
		close_minirt("error while parsing the scene");
	disk->origin = parse_vector(&file);
	disk->normal = parse_vector(&file);
	if (!vector_limit(disk->normal, -1, 1))
		close_minirt("disk orientation is out of range [-1.0, 1.0]");
	disk->normal.x = to_rad(90 * disk->normal.x);
	disk->normal.y = to_rad(90 * disk->normal.y);
	disk->normal.z = to_rad(90 * disk->normal.z);
	set_normalize(&disk->normal);
	disk->size = ft_atof(file);
	file += ft_atof_len(file);
	disk->color = get_rgb(&file);
	new = ft_lstnew(disk);
	if (!new)
		close_minirt("error while parsing the scene");
	ft_lstadd_back(lst, new);
}

void	add_triangle(t_list **lst, char *file)
{
	t_triangle	*triangle;
	t_list		*new;

	triangle = malloc(sizeof(t_triangle));
	if (!triangle)
		close_minirt("error while parsing the scene");
	triangle->p1 = parse_vector(&file);
	triangle->p2 = parse_vector(&file);
	triangle->p3 = parse_vector(&file);
	triangle->normal = get_triangle_normal(triangle);
	triangle->color = get_rgb(&file);
	new = ft_lstnew(triangle);
	if (!new)
		close_minirt("error while parsing the scene");
	ft_lstadd_back(lst, new);
}

void	add_cylinder(t_list **lst, char *file)
{
	t_cylinder	*cy;
	t_list		*new;

	cy = malloc(sizeof(t_cylinder));
	if (!cy)
		close_minirt("error while parsing the scene");
	cy->pos = parse_vector(&file);
	cy->dir = parse_vector(&file);
	if (!vector_limit(cy->dir, -1, 1))
		close_minirt("cylinder orientation is out of range [-1.0, 1.0]");
	set_normalize(&cy->dir);
	cy->radius = ft_atof(file) / 2;
	file += ft_atof_len(file);
	cy->height = ft_atof(file);
	file += ft_atof_len(file);
	cy->color = get_rgb(&file);
	new = ft_lstnew(cy);
	if (!new)
		close_minirt("error while parsing the scene");
	ft_lstadd_back(lst, new);
}
