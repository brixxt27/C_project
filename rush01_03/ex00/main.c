/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyjeon <junyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:04:07 by junyjeon          #+#    #+#             */
/*   Updated: 2022/01/19 16:44:31 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_solve.h"

int	check_ascii(char c)
{
	if (c == '\n')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int	check_available(int view_input[], char input, int *prev_input, int *iter)
{
	if ('0' < input && input <= '9')
	{
		if (*prev_input == 1)
			return (0);
		if (*iter >= 36)
			return (0);
		*prev_input = 1;
		(view_input)[*iter] = input - '0';
		(*iter)++;
	}
	else if (!check_ascii(input))
		return (0);
	else
		*prev_input = 0;
	return (1);
}

int	get_arguments(int view_input[], int argc, char *argv[])
{
	char	*input;
	int		i;
	int		prev_input_seq;

	if (argc != 2)
		return (0);
	input = argv[1];
	i = 0;
	while (*input != '\0')
	{
		if (!check_available(view_input, *input, &prev_input_seq, &i))
		{
			return (0);
		}
		input++;
	}
	if (i % 4 != 0)
		return (0);
	return (i / 4);
}

int	check_input_available(int view_input[], int n)
{
	int	iter;
	int	max;

	iter = 0;
	max = n * 4;
	while (iter < max)
	{
		if (view_input[iter] > n || view_input[iter] < 1)
			return (0);
		iter++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	input_view_count[36];
	int	main_result;
	int	size_side;

	main_result = 1;
	size_side = get_arguments(input_view_count, argc, argv);
	if (!size_side || ! check_input_available(input_view_count, size_side))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	create_matrix(&g_board, size_side);
	create_visit_row_col(&g_row_visit, &g_col_visit, size_side);
	if (solve(size_side, 0, input_view_count))
	{
		print_matrix(&g_board, size_side);
		main_result = 0;
	}
	else
		write(1, "Error\n", 6);
	erase_matrix(&g_board, size_side);
	erase_visit_row_col(&g_row_visit, &g_col_visit, size_side);
	system("leaks rush-01");
	return (main_result);
}
