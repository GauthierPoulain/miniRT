/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 08:07:28 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 08:09:19 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		close_minirt(char *reason)
{
	if (reason)
	{
		ft_putstr_fd("Error\n", STDERR);
		ft_putstr_fd(reason, STDERR);
		ft_putchar_fd('\n', STDERR);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}