/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:48:46 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 11:52:22 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_isalpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_isalnum(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

bool	ft_isascii(char c)
{
	return (c >= 0 && c <= 127);
}

bool	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}
