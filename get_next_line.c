/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:20:38 by marmoral          #+#    #+#             */
/*   Updated: 2022/08/18 00:31:53 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	static char	save[BUFFER_SIZE + 1];
	int			x;
	int			i;
	int			c;
	
	i = 0;
	c = 0;
	str = malloc(BUFFER_SIZE + 1);
	x = 1;
	if (fd == 1000 || fd < 0 || x == 0)
	{
		free(str);
		return (NULL);
	}
	if (save[0] != 0)
	{
		while (save[i])
		{
			str[i] = save[i];
			i++;
		}
		str[i] = 0;
		ft_bzero(save, ft_strlen(save));
	}
	if (ft_strchr(buf, '\n') && read(fd, buf, 1))
	{
		str[i++] = buf[0];
	}
	while (!(ft_strchr(buf, '\n')) && x > 0)
	{
		x = read(fd, buf, BUFFER_SIZE);
		printf("%s\n", buf);
		if (x > 0)
		{
			while (buf[c])
				str[i++] = buf[c++];
			c = 0;
		}
		if (x == 0)
		{
			free (str);
			return (NULL);
		}
		printf("x = %i\nbsize = %i\n", x, BUFFER_SIZE);
	}
	str[i] = 0;
	c = 0;
	i = 0;
	while (str[i] != '\n')
		i++;
	x = i;
	x++;
	if (str[i + 1] != 0)
	{
		i++;
		while (str[i])
			save[c++] = str[i++];
		save[c] = 0;
		while (str[x])
		str[x++] = 0;
	}
	return (str);
}
/*
int	main()
{
	int	fd;
	char	*str;
	int i;

	fd = open("./test1", O_RDONLY);
	str = NULL;
	i = 0;
	while(i < 3)
	{
		printf("c: %i\n", i);
		str = get_next_line(fd);
		if (!str)
		{
			free(str);
			printf("NULL");
			close (fd);
			return (0);
		}
		printf("%s", str);
		free(str);
		i++;
	}
	close (fd);
	return (0);
}
*/
//gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c && ./a.out