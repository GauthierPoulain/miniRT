/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 06:37:55 by gapoulai          #+#    #+#             */
/*   Updated: 2021/02/08 14:13:47 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct s_3dvector
{
	double	x;
	double	y;
	double	z;
}				t_3dvector;

typedef struct s_2dvector
{
	double	x;
	double	y;
}				t_2dvector;

bool		ft_malloc(size_t count, size_t size, void **dst);
bool		ft_calloc(size_t count, size_t size, void **dst);
void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *str);
size_t		ft_atoi_len(const char *str);
int			ft_atoi_base(char *str, int str_base);
double		ft_atof(char *str);
size_t		ft_atof_len(char *str);
bool		ft_isalpha(char c);
bool		ft_isdigit(char c);
bool		ft_isalnum(char c);
bool		ft_isascii(char c);
bool		ft_isprint(char c);
bool		ft_isspace(char c);
bool		ft_ischarset(char c, char *charset);
long long	ft_abs(long long value);
double		ft_dabs(double value);
long long	ft_pow(long long nb, long long power);
size_t		ft_nblen(long long nb);
char		*ft_strdup(char *s1);
size_t		ft_strlen(char *s);
bool		ft_isinrange(long long value, long long min, long long max);
char		ft_tolower(char c);
void		ft_tolowercase(char *s);
char		ft_toupper(char c);
void		ft_touppercase(char *s);
int			ft_count(char *str, char c);
char		*ft_ctos(char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoinf1(char *s1, char *s2);
char		*ft_strjoinf2(char *s1, char *s2);
char		*ft_strjoinall(char *s1, char *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strcat(char *dest, char *src);
void		ft_swap(void *a, void *b);
int			ft_get_next_line(int fd, char **line);
char		*ft_strjoinc(char *s1, char c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
long long	ft_min(long long a, long long b);
double		ft_dmin(double a, double b);
long long	ft_max(long long a, long long b);
double		ft_dmax(double a, double b);
long long	ft_sqrt(long long nb);
char		*ft_get_line(char **tab, char *start, char *end);
char		**ft_read_file(int fd);
bool		ft_endwith(char *str, char *end);
bool		ft_startwith(char *str, char *start);
int			ft_rgbtohex(int r, int g, int b);
int			ft_rgbatohex(int r, int g, int b, double a);
int			ft_hextodimhex(int hex, double a);
t_rgb		ft_hextorgb(int hex);
size_t		ft_putchar_fd(char c, int fd);
size_t		ft_putstr_fd(char *s, int fd);
size_t		ft_putnbr_fd(long long n, int fd);

#endif
