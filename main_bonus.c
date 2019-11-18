/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:26:26 by viroques          #+#    #+#             */
/*   Updated: 2019/11/18 21:28:46 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		main()
{
	int fd1;
	int fd2;
	int fd3;
	int ret1;
	int ret2;
	int ret3;
	char *line;

	fd1 = 42;
	fd2 = open("test2", O_RDONLY);
	fd3 = open("test3", O_RDONLY);
	ret1 = get_next_line(fd1, &line);
	printf("1 -- [%d] %s\n", ret1, line);
	free(line);
	ret2 = get_next_line(fd2, &line);
	printf("2 -- [%d] %s\n", ret2, line);
	free(line);
	ret3 = get_next_line(fd3, &line);
	printf("3 -- [%d] %s\n", ret3, line);
	free(line);
	ret1 = get_next_line(fd1, &line);
	printf("1 -- [%d] %s\n", ret1, line);
	free(line);
	ret2 = get_next_line(fd2, &line);
	printf("2 -- [%d] %s\n", ret2, line);
	free(line);
	ret3 = get_next_line(fd3, &line);
	printf("3 -- [%d] %s\n", ret3, line);
	free(line);
	ret1 = get_next_line(fd1, &line);
	printf("1 -- [%d] %s\n", ret1, line);
	free(line);
	ret2 = get_next_line(fd2, &line);
	printf("2 -- [%d] %s\n", ret2, line);
	free(line);
	ret3 = get_next_line(fd3, &line);
	printf("3 -- [%d] %s\n", ret3, line);
	free(line);
	close(fd1);
	close(fd2);
	close(fd3);
}