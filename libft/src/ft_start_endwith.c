/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_endwith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:50:55 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 13:00:04 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_endwith(char *str, char *end)
{
	size_t	lenstr;
	size_t	lenend;

	if (!str || !end)
		return (0);
	lenstr = ft_strlen(str);
	lenend = ft_strlen(end);
	if (lenend > lenstr)
		return (0);
	return (ft_strncmp(str + lenstr - lenend, end, lenend) == 0);
}

bool	ft_startwith(char *str, char *start)
{
	size_t	tmp;

	tmp = ft_strlen(start);
	return (!ft_memcmp(str, start, tmp) && (!str[tmp] || ft_isspace(str[tmp])));
}
