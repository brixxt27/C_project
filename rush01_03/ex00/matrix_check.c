/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyjeon <junyjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:04:51 by junyjeon          #+#    #+#             */
/*   Updated: 2022/01/16 18:04:54 by junyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_check.h"

int	try_set_row(int row_num, int value)
{
	if (g_row_visit[row_num][value - 1] == 1)
		return (0);
	g_row_visit[row_num][value - 1] = 1;
	return (1);
}

int	try_set_col(int col_num, int value)
{
	if (g_col_visit[col_num][value - 1] == 1)
		return (0);
	g_col_visit[col_num][value - 1] = 1;
	return (1);
}

void	max_change(int *max, int *cnt, int x, int y)
{
	*max = g_board[x][y] - '0';
	*cnt += 1;
}

int	count_view_rev(int view[], int n, int line)
{
	int	max[2];
	int	cnt[2];
	int	i;

	i = 0;
	cnt[0] = 0;
	max[0] = -1;
	cnt[1] = 0;
	max[1] = -1;
	while (i < n)
	{
		if (max[0] < g_board[line][i] - '0')
			max_change(max, cnt, line, i);
		if (max[1] < g_board[i][line] - '0')
			max_change(max + 1, cnt + 1, i, line);
		i++;
	}
	if ((cnt[0] == (view)[line + 2 * n]) && (cnt[1] == (view)[line]))
		return (1);
	else
		return (0);
}

int	count_view(int view[], int n, int line)
{
	int	max[2];
	int	cnt[2];
	int	i;

	i = 0;
	cnt[0] = 0;
	max[0] = -1;
	cnt[1] = 0;
	max[1] = -1;
	while (i < n)
	{
		if (max[0] < g_board[line][n - 1 - i] - '0')
			max_change(max, cnt, line, n - 1 - i);
		if (max[1] < g_board[n - 1 - i][line] - '0')
			max_change(max + 1, cnt + 1, n - 1 - i, line);
		i++;
	}
	if ((cnt[0] == (view)[line + 3 * n]) && (cnt[1] == (view)[line + n]))
		return (1);
	else
		return (0);
}
