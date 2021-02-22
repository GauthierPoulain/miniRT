/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:13:44 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/22 15:22:49 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_atof(char *str)
{
	double		ent;
	double		dec;
	size_t		i;
	int			neg;

	ent = ft_atoi(str);
	neg = 0;
	if (ent == 0)
	{
		i = 0;
		while (str[i] && i < ft_atoi_len(str))
			if (str[i++] == '-')
				neg++;
	}
	str += ft_atoi_len(str);
	if (*str != '.')
		return (ent);
	dec = ft_atoi(++str);
	dec /= ft_pow(10, ft_nblen(dec));
	if (ent < 0 || neg > 0)
		return (ent - dec);
	else
		return (ent + dec);
}

size_t	ft_atof_len(char *str)
{
	int		len;

	len = ft_atoi_len(str);
	str += len;
	if (*str != '.')
		return (len);
	len += ft_atoi_len(str + 1) + 1;
	return (len);
}
