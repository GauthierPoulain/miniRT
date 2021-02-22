/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:47:19 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 13:48:56 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long	ft_min(long long a, long long b)
{
	if (a < b)
		return (a);
	return (b);
}

double	ft_dmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

long long	ft_max(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_dmax(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}
