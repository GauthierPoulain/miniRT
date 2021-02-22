/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:41:54 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 12:42:53 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

void	ft_touppercase(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s = ft_toupper(*s);
		s++;
	}
}
