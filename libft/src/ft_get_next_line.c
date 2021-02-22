/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:13:36 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:23:42 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static bool	custom_read(int fd, char *buffer, int *readvalue)
{
	*readvalue = read(fd, buffer, 1);
	return (*readvalue != 0);
}

int	ft_get_next_line(int fd, char **line)
{
	char	buffer;
	int		ret;
	int		readvalue;

	ret = 0;
	if (!line || !ft_malloc(1, sizeof(char), (void **)line))
		return (-1);
	*line[0] = 0;
	while (custom_read(fd, &buffer, &readvalue) && buffer != '\n')
		*line = ft_strjoinc(*line, buffer);
	if (!*line)
		*line = ft_strjoinc(*line, '\0');
	if (readvalue > 0)
		ret = 1;
	return (ret);
}
