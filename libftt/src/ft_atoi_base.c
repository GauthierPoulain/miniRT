/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:25:17 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 13:11:53 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi_base(char *str, int str_base)
{
	int		i;
	int		neg;
	int		ret;

	neg = 1;
	ret = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (str[i])
	{
		if (!ft_isdigit(ft_toupper(str[i])))
			return (-1);
		if (str[i] <= '9')
			ret = (ret * str_base) + str[i] - '0';
		else
			ret = (ret * str_base) + ft_toupper(str[i]) - 55;
		i++;
	}
	return (ret * neg);
}
