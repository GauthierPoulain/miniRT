/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:12:29 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:13:35 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

size_t	ft_putnbr_fd(long long n, int fd)
{
	return (ft_putstr_fd(ft_itoa(n), fd));
}
