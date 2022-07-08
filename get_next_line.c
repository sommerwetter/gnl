/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:20:38 by marmoral          #+#    #+#             */
/*   Updated: 2022/07/08 10:50:25 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_strjoin_2(char const *s1, char const *s2)
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
	free((void *)s1);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*save;
	int			nr_b;

	nr_b = 1;
	str = malloc(BUFFER_SIZE + 1);
	if (fd == -1 || fd == 1000 || !str)
		return (NULL);
	str[BUFFER_SIZE] = 0;
	nr_b = read(fd, str, BUFFER_SIZE);
	save = ft_strdup(str);
	while (nr_b != 0)
	{
		nr_b = read(fd, str, BUFFER_SIZE);
		if (nr_b == 0)
		{
			free (str);
			return (save);
		}
		if (*str == '\n' || *str == 0)
		{
			save = ft_strjoin_2(save, str);
			free (str);
			return (save);
		}
		save = ft_strjoin_2(save, str);
	}
	free (str);
	free (save);
	return (NULL);
}

/*	if (nr_b == 0)
	{
		free (str);
		break ;
	}
*/


/*
int	main()
{
	int	fd;
	char	*str;

	fd = open("./test", O_RDONLY);
	str = NULL;
	while(1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			close(fd);
			free(str);
			break;
		}
		printf("%s\n", str);
		free (str);
	}
	close (fd);
	free(str);
	return (0);
}
*/
//gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c && ./a.out