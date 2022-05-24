/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyjeon <junyjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:05:13 by junyjeon          #+#    #+#             */
/*   Updated: 2022/01/16 18:05:15 by junyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_solve.h"

int	try_set_box(int box_level, int side_size, int depth, int view_input[])
{
	int	b_set_row;
	int	b_set_col;

	g_board[depth / side_size][depth % side_size] = box_level + '0';
	b_set_row = try_set_row(depth / side_size, box_level);
	b_set_col = try_set_col(depth % side_size, box_level);
	if (b_set_row && b_set_col)
	{
		if (solve(side_size, depth + 1, view_input))
			return (1);
		g_row_visit[depth / side_size][box_level - 1] = 0;
		g_col_visit[depth % side_size][box_level - 1] = 0;
	}
	else
	{
		if (b_set_row)
			g_row_visit[depth / side_size][box_level - 1] = 0;
		if (b_set_col)
			g_col_visit[depth % side_size][box_level - 1] = 0;
	}
	return (0);
}

int	solve(int n, int depth, int view_input[])
{
	int	box_level;

	if (depth >= n * n)
	{
		if (check_view_input_match(n, view_input))
			return (1);
	}
	else
	{
		box_level = 1;
		while (box_level <= n)
		{
			if (try_set_box(box_level, n, depth, view_input))
				return (1);
			box_level++;
		}
	}
	return (0);
}

int	check_view_input_match(int n, int view[])
{
	int	i;
	int	b_count_view_rev_match;
	int	b_count_view_match;

	i = 0;
	while (i < n)
	{
		b_count_view_rev_match = count_view_rev(view, n, i);
		b_count_view_match = count_view(view, n, i);
		if (!b_count_view_rev_match || !b_count_view_match)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
