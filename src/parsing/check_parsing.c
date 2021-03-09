/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:13:55 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/09 13:36:18 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_resolution(char *str)
{
	if (!need_space(&str))
		return (false);
	if (!need_int(&str))
		return (false);
	if (!need_space(&str))
		return (false);
	if (!need_int(&str))
		return (false);
	if (!need_eol(&str))
		return (false);
	return (true);
}

bool	check_alight(char *str)
{
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

bool	check_camera(char *str)
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
	if (!need_int(&str))
		return (false);
	if (!need_eol(&str))
		return (false);
	return (true);
}

bool	check_light(char *str)
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

void	check_line(char *line)
{
	if (is_id(line, "R") && !check_resolution(line + 1))
		close_minirt(ft_strjoin("misconfiguration in : ", line));
	else if (is_id(line, "A") && !check_alight(line + 1))
		close_minirt(ft_strjoin("misconfiguration in : ", line));
	else if (is_id(line, "c") && !check_camera(line + 1))
		close_minirt(ft_strjoin("misconfiguration in : ", line));
	else if (is_id(line, "l") && !check_light(line + 1))
		close_minirt(ft_strjoin("misconfiguration in : ", line));
}
