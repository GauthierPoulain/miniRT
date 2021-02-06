/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 07:53:30 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/06 09:59:47 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define MULTITHREADING		1

# define DEBUG				1

# define EPSILON			1e-4f

# define KEY_CHANGECAM		99

typedef	struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_cam
{
	int			id;
	t_vector	pos;
	t_vector	dir;
	int			fov;
}				t_cam;

typedef struct	s_frame
{
	void		*addr;
	void		*img;
	int			bpp;
	int			line_len;
	int			endian;
}				t_frame;

typedef struct	s_scene
{
	t_list		*cams;
	t_list		*lights;
	t_list		*spheres;
	t_list		*planes;
}				t_scene;

typedef struct	s_alight
{
	double		ratio;
	t_rgb		color;
}				t_alight;

typedef struct	s_engine
{
	void		*mlx;
	void		*window;
	char		**raw_file;
	int			size_x;
	int			size_y;
	t_alight	alight;
	bool		need_render;
	bool		save;
	t_frame		*frame;
	t_scene		scene;
	t_cam		*cam;
}				t_engine;

typedef struct	s_light
{
	t_vector	pos;
	double		brightness;
	t_rgb		color;
}				t_light;

typedef struct	s_sphere
{
	t_vector	pos;
	double		diameter;
	t_rgb		color;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	origin;
	t_vector	normal;
	t_rgb		color;
}				t_plane;

int				main(int argc, char const **argv);

int				is_id(char *str, char *id);
void			close_minirt(char *reason);
t_rgb			get_rgb(char **str);
t_vector		parse_vector(char **str);

t_engine		*init_engine(void);

void			check_scene(t_engine *engine);
void			init_scene_parts(t_engine *engine);
void			parse_scene(char **file, t_engine *engine);
void			get_file(t_engine *engine, const char *path);

void			add_alight(t_engine *engine, char *file);
void			add_sphere(t_list **lst, char *file);
void			add_camera(t_list **lst, char *file);
void			add_plane(t_list **lst, char *file);
void			add_light(t_list **lst, char *file);

t_rgb			creatergb(int r, int g, int b);

t_vector		get_vector(double x, double y, double z);

t_vector		vectoradd(t_vector s1, t_vector s2);
t_vector		vectorminus(t_vector s1, t_vector s2);
t_vector		vectormutliply(t_vector s1, double value);
t_vector		vectordivide(t_vector s1, double value);

double			dot(t_vector s1, t_vector s2);
double			sqnorm(t_vector vec);
void			set_normalize(t_vector *vec);
t_vector		get_normalize(t_vector vec);

#endif
