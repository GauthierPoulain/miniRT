/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:13:44 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/24 14:31:36 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	count_zero(char *str)
{
	size_t	i;
	size_t	zero;

	zero = 0;
	i = 0;
	while (str[i] && i < ft_atoi_len(str))
	{
		if (str[i++] == '0')
			zero++;
	}
	return (zero + 1);
}

static int	count_neg(char *str, double ent)
{
	int		res;
	size_t	i;

	res = 0;
	if (ent == 0)
	{
		i = 0;
		while (str[i] && i < ft_atoi_len(str))
			if (str[i++] == '-')
				res++;
	}
	return (res);
}

double	ft_atof(char *str)
{
	double	ent;
	double	dec;
	int		neg;
	double	zero;

	ent = ft_atoi(str);
	neg = count_neg(str, ent);
	str += ft_atoi_len(str);
	if (*str != '.')
		return (ent);
	dec = ft_atoi(++str);
	zero = count_zero(str);
	dec /= ft_pow(ft_pow(10, zero), ft_nblen(dec));
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
