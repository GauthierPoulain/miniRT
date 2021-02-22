/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:07:51 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:08:14 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_get_line(char **tab, char *start, char *end)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_startwith(tab[i], start) && ft_endwith(tab[i], end))
			return (tab[i]);
		i++;
	}
	return (NULL);
}
