/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:01:13 by mberganz          #+#    #+#             */
/*   Updated: 2023/03/29 13:58:30 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1947

char	*get_next_line(int fd);
void	*ft_calloc(size_t num, size_t size);

#endif
