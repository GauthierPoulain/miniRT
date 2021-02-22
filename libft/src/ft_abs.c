/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:53:20 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 12:13:14 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long	ft_abs(long long value)
{
	if (value < 0)
		return (-value);
	return (value);
}

double	ft_dabs(double value)
{
	if (value < 0)
		return (-value);
	return (value);
}
