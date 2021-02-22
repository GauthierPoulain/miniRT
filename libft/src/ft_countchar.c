/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:45:41 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 13:00:41 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_count(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			count++;
	return (count);
}
