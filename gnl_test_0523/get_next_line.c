/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:56:04 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/23 01:02:43 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_util	*util;
	char	*ret;
	int		size;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	util = read_file(fd);
	if (!util)
		return (NULL);
	ret = util->buf;
	free_func(util);
	return (ret);
}

t_util	*read_file(int fd)
{
	t_util	*util;

	util = malloc(sizeof(t_util));
	if (!util)
		return (NULL);
	util->buf = malloc(BUFFER_SIZE + 1);
	if (!util->buf)
		return (NULL);
	util->size = read(fd, util->buf, BUFFER_SIZE);
	if (util->size == 0)
		return (NULL);
	util->buf[BUFFER_SIZE] = '\0';
	return (util);
}

void	free_func(t_util *util)
{
	free(util->buf);
	free(util);
}