/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:41:21 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 12:43:06 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

void	ft_tolowercase(char *s)
{
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
			*s = ft_tolower(*s);
		s++;
	}
}
