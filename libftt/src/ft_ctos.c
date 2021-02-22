/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 07:15:23 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 13:38:58 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_ctos(char c)
{
	char	*res;

	if (!ft_malloc(2, sizeof(char), (void **)&res))
		return (NULL);
	res[0] = c;
	res[1] = 0;
	return (res);
}
