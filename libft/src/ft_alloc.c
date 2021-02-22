/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 06:41:44 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:33:42 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_malloc(size_t count, size_t size, void **dst)
{
	*dst = malloc(count * size);
	return (*dst != NULL);
}

bool	ft_calloc(size_t count, size_t size, void **dst)
{
	if (!ft_malloc(count, size, dst))
		return (false);
	ft_bzero(*dst, count * size);
	return (true);
}
