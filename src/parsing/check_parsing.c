/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:13:55 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/08 13:55:01 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		need_space(char **line)
{
	int		i;
	char	*str;

	str = *line;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	*line += i;
	return (i);
}

int		need_int(char **line)
{
	int		i;
	char	*str;

	str = *line;
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	*line += i;
	return (i);
}

int		need_eol(char **line)
{
	int		i;
	char	*str;

	str = *line;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i])
		return (0);
	else
		i++;
	*line += i;
	return (i);
}

int		need_double(char *str)
{

}

int		need_rgb(char *str)
{
	
}

bool	check_resolution(char *str)
{
	int		i;

	i = 0;
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
	int		i;

	i = 0;
	if ()
	return (false);
}

void	check_line(char *line)
{
	if (is_id(line, "R") && !check_resolution(line + 1))
		close_minirt(ft_strjoin("misconfiguration in : ", line));
	else if (is_id(line, "A") && !check_alight(line + 1))
		close_minirt(ft_strjoin("misconfiguration in : ", line));
	
}