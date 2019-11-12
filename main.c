/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:26:26 by viroques          #+#    #+#             */
/*   Updated: 2019/11/12 22:20:16 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main()
{
	int fd;
	int ret;
	char *line;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	write(1, line, BUFF_SIZE);
	// while (get_next_line(fd, &line))
	// 	write(1, line, BUFF_SIZE);
	close(fd);
}