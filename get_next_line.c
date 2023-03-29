/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:56:14 by mberganz          #+#    #+#             */
/*   Updated: 2023/03/29 14:02:20 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (0);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (0);
}
/*
#include <stdio.h>
int	main()
{
	char *line;
	int	fd1;
	int	fd2;
	int	fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	line = printf("%s\n", get_next_line(fd1));
	line = printf("%s\n", get_next_line(fd2));
	line = printf("%s\n", get_next_line(fd3));
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
