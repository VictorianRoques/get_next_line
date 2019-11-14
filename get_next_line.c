/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:15:27 by viroques          #+#    #+#             */
/*   Updated: 2019/11/14 21:34:56 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_strnchr(const char *s, int c, int n)
{
	int i;

	i = 0;
	while (s[i] != '\0' && i < n)
	{
		if (s[i] == c)
			return (&s[i]);
		s++;
	}
	if (s[i] == c)
		return (&s[i]);
	return (0);
}

char	*ft_strndup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;

	if (!(str = malloc(sizeof(char) * (len + 1))) || !s)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start] && i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char buff	[BUFFER_SIZE + 1];
	static char *stock;
	char *tmp;
	int read_byts;
	int i;
	int len;
	
	len = 0;
	i = 0;
	// faire un pre check
	if (!stock)
	{
		stock = malloc(sizeof(char));
		stock[0] = '\0';
	}
	while ((read_byts = read(fd, buff, BUFFER_SIZE)) && !ft_strnchr(buff, '\n', BUFFER_SIZE))
	{
		buff[read_byts] = '\0';
		tmp = stock;
		stock = ft_strjoin(tmp, buff);
		free(tmp);
	}
	buff[read_byts] = '\0';
	if (ft_strlen(buff))
		stock = ft_strjoin(stock, buff);
	*line = ft_strndup(stock);
	while (stock[i] && stock[i] != '\n')
		i++;
	tmp = ft_substr(stock, i + 1, BUFFER_SIZE);
	free(stock);
	stock = tmp;
	// printf("stock %s\n", stock); 
	// copier stock dans line \n
	// supprimer la partie copie dans mon static
	if (i || read_byts) 
		return (1);
	return (0);
}
