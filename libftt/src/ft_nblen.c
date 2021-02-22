/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:06:43 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 12:33:24 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_nblen(long long nb)
{
	size_t	len;

	len = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
