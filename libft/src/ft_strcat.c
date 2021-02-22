/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:06:35 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 12:58:33 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*rdest;

	rdest = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	return (rdest);
}
