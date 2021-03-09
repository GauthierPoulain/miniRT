/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:28:11 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/09 13:29:20 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	need_3dvector(char **line)
{
	int		i;
	char	*str;
	int		tmp;

	str = *line;
	i = 0;
	tmp = need_double(&str);
	if (!tmp)
		return (0);
	if (*str++ != ',')
		return (0);
	i += tmp + 1;
	tmp = need_double(&str);
	if (!tmp)
		return (0);
	if (*str++ != ',')
		return (0);
	i += tmp + 1;
	tmp = need_double(&str);
	if (!tmp)
		return (0);
	i += tmp;
	*line += i;
	return (i);
}
