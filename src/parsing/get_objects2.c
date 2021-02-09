/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:16:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/09 15:11:57 by gapoulai         ###   ########lyon.fr   */
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
	square->normal.y = to_rad(90 * square->normal.y + 1);
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
	disk->normal.y = to_rad(90 * disk->normal.y + 1);
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
