/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:56:14 by mberganz          #+#    #+#             */
/*   Updated: 2023/03/30 14:36:45 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (0);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	

}

#include <stdio.h>
int	main()
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd1)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd1);

	while ((line = get_next_line(fd2)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd2);

	while ((line = get_next_line(fd3)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd3);

	return (0);
}
