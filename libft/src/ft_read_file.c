/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:04:43 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:39:18 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**add_line(char **src, char *line, int i)
{
	char	**new;
	int		j;

	new = malloc((i + 2) * sizeof(char *));
	ft_bzero(new, (i + 2) * sizeof(char));
	if (!new)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new[j] = ft_strdup(src[j]);
		free(src[j++]);
	}
	new[j++] = ft_strdup(line);
	new[j] = NULL;
	free(line);
	if (i)
		free(src);
	return (new);
}

char	**ft_read_file(int fd)
{
	char	*line;
	char	**file;
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (ret)
	{
		ret = ft_get_next_line(fd, &line);
		if (ret == -1)
			return (NULL);
		if (*line)
			file = add_line(file, line, i++);
		else
			free(line);
		if (!file)
			return (NULL);
	}
	return (file);
}
