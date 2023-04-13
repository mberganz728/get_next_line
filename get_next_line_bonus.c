/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:38:53 by mberganz          #+#    #+#             */
/*   Updated: 2023/04/13 11:39:53 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*nolinebreak(char *whole_line)
{
	if (ft_strlen(whole_line) == 0)
	{
		free(whole_line);
		return (NULL);
	}
	else
		return (whole_line);
}

char	*ft_line_and_rest(char **line)
{
	char	*rest;
	char	*whole_line;
	int		i;

	i = 0;
	if (*line == NULL)
		return (NULL);
	while ((*line)[i] != '\n' && (*line)[i])
		i++;
	if ((*line)[i] == '\n')
	{
		whole_line = ft_substr(*line, 0, i + 1);
		rest = ft_strdup(*line + (i + 1));
		free(*line);
		*line = rest;
		return (nolinebreak(whole_line));
	}
	whole_line = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (nolinebreak(whole_line));
}

char	*rnsend(int read_bytes, int fd, char *buffer, char **line)
{
	char	*temp;

	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		if (*line == NULL)
			*line = ft_strdup("");
		temp = ft_strjoin(*line, buffer);
		free(*line);
		*line = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_line_and_rest(line));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line[1024];
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(buffer);
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	return (rnsend(read_bytes, fd, buffer, &line[fd]));
}
/*
#include <stdio.h>
int	main()
{
	char	*line = NULL;
	//char	*line2 = NULL;
	int		fd1, fd2, fd3;

	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd1)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
	while ((line = get_next_line(fd2)))
	{	
		printf("%s", line);
		free(line);
	}
	close(fd2);
	while ((line = get_next_line(fd3)))
	{
		printf("%s", line);
		free(line);
	}
//	system("leaks -q a.out");
	close(fd3);
	return (0);
}*/
