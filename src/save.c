/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:22:27 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/08 11:17:12 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	write_custom(int fd, unsigned int val)
{
	char	tmp;

	tmp = val;
	write(fd, &tmp, 1);
}

void	init_header(unsigned int *headers, t_engine *engine, int eb)
{
	int	paddedsize;

	paddedsize = engine->size_y;
	paddedsize = ((engine->size_x * 3) + eb) *paddedsize;
	headers[0] = paddedsize + 54;
	headers[1] = 0;
	headers[2] = 54;
	headers[3] = 40;
	headers[4] = engine->size_x;
	headers[5] = -engine->size_y;
	headers[7] = 0;
	headers[8] = paddedsize;
	headers[9] = 0;
	headers[10] = 0;
	headers[11] = 0;
	headers[12] = 0;
}

void	write_header(int outfile, unsigned int *headers)
{
	int	i;

	write(outfile, "BM", 2);
	i = -1;
	while (++i <= 5)
	{
		write_custom(outfile, headers[i] & 0x000000FF);
		write_custom(outfile, (headers[i] & 0x0000FF00) >> 8);
		write_custom(outfile, (headers[i] & 0x00FF0000) >> 16);
		write_custom(outfile, (headers[i] & (unsigned int) 0xFF000000) >> 24);
	}
	write_custom(outfile, 1);
	write_custom(outfile, 0);
	write_custom(outfile, 24);
	write_custom(outfile, 0);
	i = 6;
	while (++i <= 12)
	{
		write_custom(outfile, headers[i] & 0x000000FF);
		write_custom(outfile, (headers[i] & 0x0000FF00) >> 8);
		write_custom(outfile, (headers[i] & 0x00FF0000) >> 16);
		write_custom(outfile, (headers[i] & (unsigned int) 0xFF000000) >> 24);
	}
}

void	imgcpy(int fd, int extrabites, t_engine *engine)
{
	int		x;
	int		y;
	t_rgb	tmp;
	int		blen;
	char	*buffer;

	y = 0;
	while (y < engine->size_y)
	{
		ft_calloc((3 * engine->size_x) + extrabites, sizeof(char),
				(void **)&buffer);
		blen = 0;
		x = 0;
		while (x < engine->size_x)
		{
			tmp = get_pixel_color(engine, x, y);
			buffer[blen++] = tmp.r;
			buffer[blen++] = tmp.g;
			buffer[blen++] = tmp.b;
			x++;
		}
		write(fd, buffer, (3 * engine->size_x) + extrabites);
		free(buffer);
		y++;
	}
}

void	get_save(t_engine *engine, char *filename)
{
	unsigned int	headers[13];
	int				outfile;
	int				extrabytes;

	if (DEBUG)
		printf("start render\n");
	render(engine);
	if (DEBUG)
		printf("start save\n");
	extrabytes = 4 - ((engine->size_x * 3) % 4);
	if (extrabytes == 4)
		extrabytes = 0;
	init_header(headers, engine, extrabytes);
	outfile = open(filename, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0775);
	write_header(outfile, headers);
	imgcpy(outfile, extrabytes, engine);
	close(outfile);
}
