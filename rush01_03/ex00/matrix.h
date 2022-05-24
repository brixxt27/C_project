/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyjeon <junyjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:04:27 by junyjeon          #+#    #+#             */
/*   Updated: 2022/01/16 18:06:04 by junyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <stdlib.h>
# include <unistd.h>

void	create_matrix(char ***matrix, int side_size);
void	erase_matrix(char ***matrix, int side_size);
void	print_matrix(char ***matrix, int side_size);
void	create_visit_row_col(int ***row, int ***col, int n);
void	erase_visit_row_col(int ***row, int ***col, int side_size);
#endif
