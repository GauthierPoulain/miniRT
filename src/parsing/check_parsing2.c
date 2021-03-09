/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:37:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/09 13:53:56 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_sphere(char *str)
{
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_double(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_rgb(&str))
		return (false);
	if (!need_eol(&str))
		return (false);
	return (true);
}

bool	check_plane(char *str)
{
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_rgb(&str))
		return (false);
	if (!need_eol(&str))
		return (false);
	return (true);
}

bool	check_square(char *str)
{
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_double(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_rgb(&str))
		return (false);
	if (!need_eol(&str))
		return (false);
	return (true);
}

bool	check_cylinder(char *str)
{
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_double(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_double(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_rgb(&str))
		return (false);
	if (!need_eol(&str))
		return (false);
	return (true);
}

bool	check_triangle(char *str)
{
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_3dvector(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_rgb(&str))
		return (false);
	if (!need_eol(&str))
		return (false);
	return (true);

}
