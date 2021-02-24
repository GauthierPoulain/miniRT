/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 08:07:28 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/24 13:59:29 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	is_id(char *str, char *id)
{
	size_t	tmp;

	tmp = ft_strlen(id);
	return (!ft_strncmp(str, id, tmp) && (!str[tmp] || ft_isspace(str[tmp])));
}

void	close_minirt(char *reason)
{
	if (reason)
	{
		ft_putstr_fd("Error\n", STDERR);
		ft_putstr_fd(reason, STDERR);
		ft_putchar_fd('\n', STDERR);
		exit(EXIT_FAILURE);
	}
	printf("exit without issues\n");
	exit(EXIT_SUCCESS);
}

t_rgb	get_rgb(char **str)
{
	t_rgb	color;

	color.r = ft_atoi(*str);
	*str += ft_atoi_len(*str);
	if (**str != ',')
		close_minirt("wrong rgb format");
	*str += 1;
	color.g = ft_atoi(*str);
	*str += ft_atoi_len(*str);
	if (**str != ',')
		close_minirt("wrong rgb format");
	*str += 1;
	color.b = ft_atoi(*str);
	*str += ft_atoi_len(*str);
	if (!ft_isinrange(color.r, 0, 255) || !ft_isinrange(color.g, 0, 255)
		|| !ft_isinrange(color.b, 0, 255))
		close_minirt("wrong rgb format");
	return (creatergb(color.r, color.g, color.b));
}

t_vector	parse_vector(char **str)
{
	t_vector	vec;

	vec.x = ft_atof(*str);
	*str += ft_atof_len(*str);
	if (**str != ',')
		close_minirt("wrong vector format");
	*str += 1;
	vec.y = ft_atof(*str);
	*str += ft_atof_len(*str);
	if (**str != ',')
		close_minirt("wrong vector format");
	*str += 1;
	vec.z = ft_atof(*str);
	*str += ft_atof_len(*str);
	return (vec);
}

double	to_rad(double angle)
{
	return (angle * PI * 0.5);
}
