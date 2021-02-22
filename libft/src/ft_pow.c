/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:22:23 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 12:33:33 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long	ft_pow(long long nb, long long power)
{
	if (power < 0)
		return (0);
	if (power < 1)
		return (1);
	else
		return (nb * ft_pow(nb, power - 1));
}
