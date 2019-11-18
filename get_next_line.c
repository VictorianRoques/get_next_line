/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:15:27 by viroques          #+#    #+#             */
/*   Updated: 2019/11/18 21:06:28 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		ft_cutncpy_stock(char **stock)
{
	int		i;
	char	*tmp;
	char	*toto;

	i = 0;
	toto = *stock;
	while (toto[i])
	{
		if (toto[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	tmp = *stock;
	*stock = ft_substr(tmp, i, ft_strlen(tmp));
	free(tmp);
}

static int		ft_readnstock(int fd, char *buff, char **stock)
{
	int		read_bytes;
	char	*tmp;

	while ((read_bytes = read(fd, buff, BUFFER_SIZE))
			&& !ft_strnchr(buff, '\n', BUFFER_SIZE))
	{
		if (read_bytes == -1)
			return (-1);
		buff[read_bytes] = '\0';
		tmp = *stock;
		*stock = ft_strjoin(tmp, buff);
		free(tmp);
	}
	if (read_bytes == -1)
		return (-1);
	buff[read_bytes] = '\0';
	tmp = *stock;
	*stock = ft_strjoin(tmp, buff);
	free(tmp);
	return (read_bytes);
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*stock[OPEN_MAX];
	int				read_bytes;
	int				i;

	i = 0;
	if (fd < 0 || !line || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	if (!stock[fd])
	{
		if (!(stock[fd] = malloc(sizeof(char))))
			return (-1);
		stock[fd][0] = '\0';
	}
	if ((read_bytes = ft_readnstock(fd, buff, &stock[fd])) == -1)
	{
		*line = NULL;
		return (-1);
	}
	*line = ft_strndup(stock[fd]);
	if (!ft_strnchr(stock[fd], '\n', ft_strlen(stock[fd])) && read_bytes == 0)
		return (0);
	ft_cutncpy_stock(&stock[fd]);
	return (1);
}
