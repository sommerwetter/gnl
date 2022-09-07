/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:20:41 by marmoral          #+#    #+#             */
/*   Updated: 2022/09/07 12:47:01 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if ((char)c == str[i])
				return ((char *)&str[i]);
			i++;
		}
		if ((char)c == str[i])
			return ((char *)&str[i]);
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	sub = NULL;
	if (len > ft_strlen(s))
		sub = malloc(ft_strlen(s) + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = 0;
	return (sub);
}

char	*ft_strdup(char *s1)
{
	char	*s1_cpy;
	size_t	i;

	i = 0;
	s1_cpy = malloc(ft_strlen(s1) + 1);
	if (!s1_cpy)
		return (NULL);
	while (i < ft_strlen(s1) + 1)
	{
		((char *)s1_cpy)[i] = ((char *)s1)[i];
		i++;
	}
	return (s1_cpy);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;
	size_t	src_l;
	size_t	ans;

	i = 0;
	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	ans = 0;
	if (size < dst_l)
	{
		ans = src_l + size;
		return (ans);
	}
	else
		ans = dst_l + src_l;
	while (src[i] && dst_l < size - 1 && size > 0)
	{
		dst[dst_l] = src[i];
		dst_l++;
		i++;
	}
	dst[dst_l] = 0;
	return (ans);
}

char	*new_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = malloc(size_s1 + size_s2 + 1);
	if (!new)
		return (NULL);
	while (i < size_s1 + 1)
	{
		((char *)new)[i] = ((char *)s1)[i];
		i++;
	}
	ft_strlcat(new, s2, size_s1 + size_s2 + 1);
	free(s1);
	return (new);
}
