/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:51:17 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 13:57:23 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long	ft_sqrt(long long nb)
{
	long long	i;

	if (nb < 0 || nb > 3037000499 * 3037000499)
		return (0);
	i = 1;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
