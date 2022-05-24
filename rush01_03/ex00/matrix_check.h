/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_check.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyjeon <junyjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:05:05 by junyjeon          #+#    #+#             */
/*   Updated: 2022/01/16 18:05:08 by junyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_CHECK_H
# define MATRIX_CHECK_H
# include "matrix.h"

int		try_set_row(int row_num, int value);
int		try_set_col(int col_num, int value);
void	max_change(int *max, int *cnt, int x, int y);
int		count_view(int view[], int n, int line);
int		count_view_rev(int view[], int n, int line);

int		**g_row_visit;
int		**g_col_visit;
char	**g_board;

#endif
