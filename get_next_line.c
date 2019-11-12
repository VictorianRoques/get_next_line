/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:15:27 by viroques          #+#    #+#             */
/*   Updated: 2019/11/12 23:51:27 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char *p;

	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == c)
			return (p);
		p++;
	}
	if (*p == c)
		return (p);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char buff[BUFFER_SIZE + 1];
	int ret;
	int i;
	char *tmp;

	i = 0;
	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		*line = ft_strjoin(*line, buff);
	}
	if (ft_strchr(buff, '\n') != NULL)
		return (1);
	if (ft_strchr(buff, '\0') != NULL)
		return (0);
	return (0);
}
