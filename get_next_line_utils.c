/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:21:30 by fcelesti          #+#    #+#             */
/*   Updated: 2021/12/20 16:15:21 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *before, char *buf)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!before)
	{
		before = (char *)malloc(sizeof(char) * 1);
		before[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(before) + ft_strlen(buf)) + 1));
	if (str == NULL)
		return (0);
	i = -1;
	j = 0;
	if (before)
		while (before[++i])
			str[i] = before[i];
	while (buf[j])
		str[i++] = buf[j++];
	str[ft_strlen(before) + ft_strlen(buf)] = '\0';
	free(before);
	return (str);
}
