/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:20:38 by marmoral          #+#    #+#             */
/*   Updated: 2022/09/07 13:08:25 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*lesen(int fd, char *save)
{
	int		x;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	x = 1;
	while (!ft_strchr(save, '\n') && x != 0)
	{
		x = read(fd, buff, BUFFER_SIZE);
		if (x == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[x] = 0;
		save = new_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*return_line(char *save)
{
	char	*rturn;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	i++;
	return (rturn = ft_substr(save, 0, i));
}

char	*reset(char *save)
{
	char	*rest;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	i++;
	rest = ft_substr(save, i, ft_strlen(save));
	free(save);
	return (rest);
	
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*rturn;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = lesen(fd, save);
	if (!save)
		return (NULL);
	rturn = return_line(save);
	save = reset(save);
	return (rturn);
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