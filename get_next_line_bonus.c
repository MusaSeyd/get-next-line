/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:21:16 by fcelesti          #+#    #+#             */
/*   Updated: 2021/12/26 13:19:18 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*before_nl(char *before)
{
	int		i;
	char	*before_nl;

	i = 0;
	if (!before[i])
		return (0);
	while (before[i] && before[i] != '\n')
		i++;
	before_nl = (char *)malloc(sizeof(char) * (i + 2));
	if (!before_nl)
		return (0);
	i = 0;
	while (before[i] && before[i] != '\n')
	{
		before_nl[i] = before[i];
		i++;
	}
	if (before[i] == '\n')
		before_nl[i++] = '\n';
	before_nl[i] = '\0';
	return (before_nl);
}

char	*after_nl(char *before)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (before[i] && before[i] != '\n')
		i++;
	if (!before[i])
	{
		free(before);
		return (0);
	}
	new_line = (char *)malloc(sizeof(char) * (ft_strlen(before) - i + 1));
	if (!new_line)
		return (0);
	j = 0;
	while (before[++i])
		new_line[j++] = before[i];
	new_line[j] = '\0';
	free(before);
	return (new_line);
}

char	*rd_before(int fd, char *before)
{
	int		bytes;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	bytes = 1;
	while (bytes != 0 && !(ft_strchr(before, '\n')))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (0);
		}
		buf[bytes] = '\0';
		before = ft_strjoin(before, buf);
	}
	free(buf);
	return (before);
}

char	*get_next_line(int fd)
{
	static char	*before[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	before[fd] = rd_before(fd, before[fd]);
	if (!before[fd])
		return (0);
	line = before_nl(before[fd]);
	before[fd] = after_nl(before[fd]);
	return (line);
}

// int main ()
// {
// 	int fd;

// 	fd  = open("text.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }