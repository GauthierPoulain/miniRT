/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgbconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:11:12 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:39:37 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_rgbtohex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	ft_rgbatohex(int r, int g, int b, double a)
{
	r = ft_min(255, r * a);
	g = ft_min(255, g * a);
	b = ft_min(255, b * a);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	ft_hextodimhex(int hex, double a)
{
	int	r;
	int	g;
	int	b;

	r = ft_min(255, hex >> 16);
	g = ft_min(255, (hex & 0x00ff00) >> 8);
	b = ft_min(255, (hex & 0x0000ff));
	return (ft_rgbatohex(r, g, b, a));
}

t_rgb	ft_hextorgb(int hex)
{
	t_rgb	rgb;

	rgb.r = ft_min(255, hex >> 16);
	rgb.g = ft_min(255, (hex & 0x00ff00) >> 8);
	rgb.b = ft_min(255, (hex & 0x0000ff));
	return (rgb);
}
