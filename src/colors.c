/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:40:52 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 09:41:44 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb	creatergb(int r, int g, int b)
{
	t_rgb	new;

	new.r = r;
	new.b = b;
	new.g = g;
	return (new);
}
