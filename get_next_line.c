/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:15:27 by viroques          #+#    #+#             */
/*   Updated: 2019/11/18 20:17:10 by viroques         ###   ########.fr       */
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

	read_bytes = 0;
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
	buff[read_bytes] = '\0';
	tmp = *stock;
	*stock = ft_strjoin(tmp, buff);
	free(tmp);
	return (read_bytes);
}

int				get_next_line(int fd, char **line)
{
	char			buff	[BUFFER_SIZE + 1];
	static char		*stock;
	int				read_bytes;
	int				i;

	i = 0;
	if (fd < 0 || !line || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	if (!stock)
	{
		if (!(stock = malloc(sizeof(char))))
			return (-1);
		stock[0] = '\0';
	}
	read_bytes = ft_readnstock(fd, buff, &stock);
	*line = ft_strndup(stock);
	if (!ft_strnchr(stock, '\n', ft_strlen(stock)) && read_bytes == 0)
		return (0);
	ft_cutncpy_stock(&stock);
	return (1);
}
