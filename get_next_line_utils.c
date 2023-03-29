/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:13:15 by mberganz          #+#    #+#             */
/*   Updated: 2023/03/29 13:58:03 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (size == SIZE_MAX || num == SIZE_MAX)
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
