/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:56:14 by mberganz          #+#    #+#             */
/*   Updated: 2023/03/31 17:58:25 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (size > 0 && num > 0 && (size > SIZE_MAX / num))
		return (0);
	ptr = (char *)malloc(num * size);
	if (!ptr)
		return (0);
	while (i < (num * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
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
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	static char	*line = "";
	int			read_bytes;
	int			i;

	i = 0;
	temp = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), (sizeof(char)));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buffer[read_bytes] = '\0';
		if (buffer[i] != '\n')
		{
			line = ft_strjoin(line, buffer);
			i++;
		}
		if (buffer[i] == '\n')
			break;
	}
	free(buffer);
	return (line);
}

#include <stdio.h>
int	main()
{
	char	*line = "";
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while (line == get_next_line(fd1))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd1);

	while (line == get_next_line(fd2))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd2);

	while (line == get_next_line(fd3))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd3);

	return (0);
}
