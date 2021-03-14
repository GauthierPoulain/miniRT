/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:05:06 by gapoulai          #+#    #+#             */
/*   Updated: 2021/03/14 08:01:25 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!ft_calloc(len + 1, sizeof(char), (void **)& res))
		return (NULL);
	if (s1)
		ft_memcpy(res, s1, ft_strlen(s1));
	if (s2)
		ft_strcat(res, (char *)s2);
	return (res);
}

char	*ft_strjoinf1(char *s1, char *s2)
{
	size_t	len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!ft_calloc(len + 1, sizeof(char), (void **)& res))
		return (NULL);
	if (s1)
		ft_memcpy(res, s1, ft_strlen(s1));
	if (s2)
		ft_strcat(res, (char *)s2);
	free(s1);
	return (res);
}

char	*ft_strjoinf2(char *s1, char *s2)
{
	size_t	len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!ft_calloc(len + 1, sizeof(char), (void **)& res))
		return (NULL);
	if (s1)
		ft_memcpy(res, s1, ft_strlen(s1));
	if (s2)
		ft_strcat(res, (char *)s2);
	free(s2);
	return (res);
}

char	*ft_strjoinall(char *s1, char *s2)
{
	size_t	len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!ft_calloc(len + 1, sizeof(char), (void **)& res))
		return (NULL);
	if (s1)
		ft_memcpy(res, s1, ft_strlen(s1));
	if (s2)
		ft_strcat(res, (char *)s2);
	free(s1);
	free(s2);
	return (res);
}

char	*ft_strjoinc(char *s1, char c)
{
	int		i;
	int		tlen;
	char	*res;

	i = 0;
	if (!s1)
	{
		if (!ft_malloc(2, sizeof(char), (void **)& res))
			return (NULL);
		res[0] = c;
		res[1] = 0;
		return (res);
	}
	tlen = ft_strlen(s1) + 1;
	if (!ft_malloc(tlen + 1, sizeof(char), (void **)& res))
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = 0;
	free(s1);
	return (res);
}
