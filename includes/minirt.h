/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 07:53:30 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/11 13:26:50 by gapoulai         ###   ########lyon.fr   */
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

# define DEBUG				0

# ifdef BONUS
#  define MULTITHREADING
#  define NPROCS			4
#  define CY_CAPS			1
# else
#  define CY_CAPS			0
# endif

# define WINDOW_NAME	"miniRT"

# define PI 				3.1415
# define EPSILON			1e-4
# define ALBEDO				.4
# define LIGHT_MULT			10

# define KEY_EXIT			53
# define KEY_CHANGECAM		8

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct s_cam
{
	int			id;
	t_vector	pos;
	t_vector	dir;
	int			fov;
}				t_cam;

typedef struct s_frame
{
	void		*addr;
	void		*img;
	int			bpp;
	int			line_len;
	int			endian;
}				t_frame;

typedef struct s_scene
{
	t_list		*cams;
	t_list		*lights;
	t_list		*spheres;
	t_list		*planes;
	t_list		*squares;
	t_list		*disks;
	t_list		*triangles;
	t_list		*cylinders;
}				t_scene;

typedef struct s_alight
{
	double		ratio;
	t_rgb		color;
}				t_alight;

typedef struct s_engine
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

typedef struct s_light
{
	t_vector	pos;
	double		brightness;
	t_rgb		color;
}				t_light;

typedef struct s_sphere
{
	t_vector	pos;
	double		radius;
	t_rgb		color;
}				t_sphere;

typedef struct s_plane
{
	t_vector	origin;
	t_vector	normal;
	t_rgb		color;
}				t_plane;

typedef struct s_square
{
	t_vector	origin;
	t_vector	normal;
	double		size;
	t_rgb		color;
}				t_square;

typedef struct s_triangle
{
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	t_vector	normal;
	t_rgb		color;
}				t_triangle;

typedef struct s_cylinder
{
	t_vector	pos;
	t_vector	dir;
	double		radius;
	double		height;
	t_rgb		color;
}				t_cylinder;

typedef struct s_hit
{
	double		t;
	t_vector	pos;
	t_vector	normal;
	t_rgb		color;
}				t_hit;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	dir;
	double		min;
}				t_ray;

typedef struct s_thread_data
{
	t_engine	*engine;
	int			from;
	int			to;
	int			id;
}				t_thread_data;

typedef struct s_light_managment
{
	t_list	*lights;
	t_light	*light;
	t_ray	to_light;
	void	*obstacle;
	t_hit	hit_obstacle;
	t_rgb	diffuse;
	t_rgb	color_l;
	double	normal_dot_light;
}				t_light_managment;

typedef struct s_cyresolve
{
	double		tmin;
	t_vector	t;
	t_vector	b;
	t_vector	normal;
}				t_cyresolve;

int				main(int argc, char const **argv);
int				is_id(char *str, char *id);
void			close_minirt(char *reason);
t_rgb			get_rgb(char **str);
t_vector		parse_vector(char **str);
double			to_rad(double angle);
t_engine		*init_engine(void);
int				get_resolution(char **str);
void			get_win_size(t_engine *engine, int save);
void			init_window(t_engine *engine);
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
t_rgb			mult_rgb_rgb(t_rgb rgb, t_rgb mult);
t_rgb			mult_rgb_double(t_rgb rgb, double mult);
t_rgb			add_rgb_rgb(t_rgb rgb, t_rgb add);
void			min_rgb(t_rgb *color);
t_vector		get_vector(double x, double y, double z);
double			distance(t_vector p1, t_vector p2);
t_vector		vectoradd(t_vector s1, t_vector s2);
t_vector		vectorminus(t_vector s1, t_vector s2);
t_vector		vectormutliply(t_vector s1, double value);
t_vector		vectordivide(t_vector s1, double value);
double			dot(t_vector s1, t_vector s2);
double			sqnorm(t_vector vec);
void			set_normalize(t_vector *vec);
t_vector		get_normalize(t_vector vec);
bool			vector_limit(t_vector vec, double min, double max);
void			set_pixel_color(t_engine *engine, int x, int y, int color);
t_rgb			get_pixel_color(t_engine *engine, int x, int y);
void			init_frame(t_engine *engine);
void			change_camera(t_engine *engine);
int				key_event(int key, t_engine *engine);
int				close_event(void);
int				loop_event(t_engine *engine);
void			engine_event(t_engine *engine);
void			write_custom(int fd, unsigned int val);
void			init_header(unsigned int *headers, t_engine *engine, int eb);
void			write_header(int outfile, unsigned int *headers);
void			imgcpy(int fd, int extrabites, t_engine *engine);
void			get_save(t_engine *engine, char *filename);
void			render(t_engine *engine);
t_ray			new_ray(t_vector origin, t_vector dir);
t_ray			init_ray(t_engine *engine, t_cam cam, int x, int y);
t_vector		set_ray_direction(t_engine *engine, t_cam cam, int x, int y);
void			do_raytracing(t_thread_data *thread, int x, int y);
bool			secdegsolve(t_vector point, double *t1, double *t2);
void			raytrace_spheres(t_ray ray, t_scene *scene, t_hit *hit, void
					**obj);
double			ft_max_double(double a, double b);
double			ft_min_double(double a, double b);
bool			intersect_plane(const t_ray ray, const t_plane plane, t_hit
					*hit);
void			raytrace_planes(t_ray ray, t_scene *scene, t_hit *hit, void
					**obj);
t_vector		normaltodeg(t_vector vec);
void			add_disk(t_list **lst, char *file);
void			add_square(t_list **lst, char *file);
void			raytrace_square(t_ray ray, t_scene *scene, t_hit *hit, void
					**obj);
void			raytrace_disk(t_ray ray, t_scene *scene, t_hit *hit, void
					**obj);
t_rgb			moy_rgb_rgb(t_rgb rgb1, t_rgb rgb2);
t_vector		vectorcross(t_vector v1, t_vector v2);
void			raytrace_triangle(t_ray ray, t_scene *scene, t_hit *hit, void
					**obj);
t_vector		get_triangle_normal(t_triangle *triangle);
void			add_triangle(t_list **lst, char *file);
void			add_cylinder(t_list **lst, char *file);
void			raytrace_cylinder(t_ray ray, t_scene *scene, t_hit *hit, void
					**obj);
t_vector		apply_rot(t_vector pos, t_vector dir, t_vector rot);
t_vector		process_normal_cy(t_ray ray, t_vector normal);
double			intersect_caps_cy(t_ray ray, t_cylinder cy, t_vector pos);
double			calc_c_cy(t_ray ray, t_cylinder cy, t_vector t, t_vector b);
t_vector		calclanormalparceqttroplongue(t_cylinder cy, t_vector p);
double			magnitude(t_vector v);
void			check_normal(t_vector vec);
void			check_caps(t_ray ray, t_cyresolve *res, t_cylinder cy);
double			to_deg(double angle);
void			check_line(char *line);
bool			check_resolution(char *str);
int				need_space(char **line);
int				need_int(char **line);
int				need_eol(char **line);
int				need_double(char **line);
int				need_rgb(char **line);
int				need_3dvector(char **line);
bool			check_sphere(char *str);
bool			check_plane(char *str);
bool			check_square(char *str);
bool			check_cylinder(char *str);
bool			check_triangle(char *str);
t_vector		vec3_rotatex(t_vector vec3, double alpha);
t_vector		vec3_rotatey(t_vector vec3, double beta);
t_vector		vec3_rotatez(t_vector vec3, double gamma);
t_vector		vec3_rotatexyz(t_vector vec3, t_vector ovec3);

#endif