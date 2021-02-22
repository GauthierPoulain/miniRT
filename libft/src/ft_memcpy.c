/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:40:37 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 13:00:14 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*castd;
	const char	*casts;

	if (!dst && !src)
		return (NULL);
	castd = dst;
	casts = src;
	while (n--)
		*castd++ = *casts++;
	return (dst);
}
