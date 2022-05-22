/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:13:20 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/19 16:16:32 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
    # define BUFFER_SIZE 1;
# endif
typedef struct s_util
{
    char    *buf;
    int     size;
} t_util;

char	*get_next_line(int fd);
t_util	*read_file(int fd);
void	free_func(t_util *util);

#endif