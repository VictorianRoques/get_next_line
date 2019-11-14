/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:18:30 by viroques          #+#    #+#             */
/*   Updated: 2019/11/14 16:20:44 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define OPEN_MAX 10240
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
#endif