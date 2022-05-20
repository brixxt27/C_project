/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:25:31 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/20 15:41:57 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buf;
	int			ret_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = allocate_memory();
	ret_read = read_data(fd, &buf);
	if (!ret_read)
		return (NULL);
	return (buf);
}

char	*allocate_memory(void)
{
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	return (buf);
}

int	read_data(int fd, char **pbuf)
{
	int	ret_read;

	ret_read = read(fd, *pbuf, BUFFER_SIZE);
	return (ret_read);
}