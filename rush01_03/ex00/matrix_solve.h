/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_solve.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyjeon <junyjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:05:19 by junyjeon          #+#    #+#             */
/*   Updated: 2022/01/16 18:05:21 by junyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_SOLVE_H
# define MATRIX_SOLVE_H
# include "matrix_check.h"

int	try_set_box(int box_level, int side_size, int depth, int view_input[]);
int	solve(int n, int depth, int view_input[]);
int	check_view_input_match(int n, int view[]);

#endif
