/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:25:31 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/19 17:23:57 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	int		size;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 1) == 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	buf[BUFFER_SIZE] = '\0';
	size = read(fd, buf, BUFFER_SIZE);
	// if (size == 0)
	// 	return (NULL);
	return (buf);
}