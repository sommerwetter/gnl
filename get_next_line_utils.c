/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:20:41 by marmoral          #+#    #+#             */
/*   Updated: 2022/07/02 04:49:47 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;

	s1_cpy = malloc(ft_strlen(s1) + 1);
	if (!s1_cpy)
		return (NULL);
	ft_memcpy(s1_cpy, s1, ft_strlen(s1) + 1);
	return (s1_cpy);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = malloc(size_s1 + size_s2 + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, size_s1 + 1);
	ft_strlcat(new, s2, size_s1 + size_s2 + 1);
	return (new);
}
