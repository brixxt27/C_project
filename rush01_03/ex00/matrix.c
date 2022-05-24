/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyjeon <junyjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:04:16 by junyjeon          #+#    #+#             */
/*   Updated: 2022/01/16 18:18:34 by junyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	create_matrix(char ***matrix, int side_size)
{
	int	size_ptr_loc;
	int	size_int_loc;
	int	iter_create;
	int	iter_row;

	size_ptr_loc = sizeof(char *) * side_size;
	size_int_loc = sizeof(char) * side_size;
	(*matrix) = (char **)malloc(size_ptr_loc);
	iter_create = 0;
	iter_row = 0;
	while (iter_create < side_size)
	{
		(*matrix)[iter_create] = (char *)malloc(size_int_loc);
		while (iter_row < side_size)
		{
			(*matrix)[iter_create][iter_row] = '0';
			iter_row++;
		}
		iter_row = 0;
		iter_create++;
	}
}

void	erase_matrix(char ***matrix, int side_size)
{
	int	iter;

	iter = 0;
	while (iter < side_size)
	{
		free((*matrix)[iter]);
		iter++;
	}
	free(*matrix);
}

void	print_matrix(char ***matrix, int side_size)
{
	int	iter_y;
	int	iter_x;

	iter_x = 0;
	iter_y = 0;
	while (iter_y < side_size)
	{
		while (iter_x < side_size)
		{
			write(1, &(*matrix)[iter_y][iter_x], 1);
			if (iter_x < side_size - 1)
				write(1, " ", 1);
			iter_x++;
		}
		iter_x = 0;
		write(1, "\n", 1);
		iter_y++;
	}
}

void	create_visit_row_col(int ***row_visit, int ***col_visit, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(*row_visit) = (int **)malloc(sizeof(int *) * n);
	(*col_visit) = (int **)malloc(sizeof(int *) * n);
	while (i < n)
	{
		(*row_visit)[i] = (int *)malloc(4 * n);
		(*col_visit)[i] = (int *)malloc(4 * n);
		while (j < n)
		{
			(*col_visit)[i][j] = 0;
			(*row_visit)[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	erase_visit_row_col(int ***row, int ***col, int side_size)
{
	int	iter;

	iter = 0;
	while (iter < side_size)
	{
		free((*row)[iter]);
		free((*col)[iter]);
		iter++;
	}
	free(*row);
	free(*col);
}
