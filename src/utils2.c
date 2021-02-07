/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:23:47 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 16:25:38 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	ft_max_double(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_min_double(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

