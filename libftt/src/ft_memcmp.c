/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 07:40:35 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 13:00:28 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (s1 == s2)
		return (0);
	i = 0;
	while (i < n && (*(uint8_t *)s1 == *(uint8_t *)s2))
	{
		i++;
		s1 = 1 + (uint8_t *)s1;
		s2 = 1 + (uint8_t *)s2;
	}
	if (i == n)
		return (0);
	return ((*(uint8_t *)s1 - *(uint8_t *)s2));
}
