/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:57:49 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 17:42:53 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

#define SIDE_NBR 4

#define CLUE		0
#define GRID_SIZE	0
#define SET			1
#define SET_SIZE	1

#define TOP		0
#define BOTTOM	1
#define LEFT	2
#define RIGHT	3

#define SUCCESS	1
#define FAILURE	0

/* STUFF FOR SRC2 VERSION */
int		ft_strlen(char *str);
int		ft_factorial(int nb);
void	free_2darray(int **arr, int n);
void	free_set(int **arr, int n);
int		**parse_clue(char *argv, int clue_len, int n);
int		**set_permutation(int n, int set_size);
void	generate_comb(int **set, int *comb, int n, int col);

int		solve_puzzle(int *grid, int ***data, int n, int set_size);
int		row_is_bad(int *grid, int ***data, int *arr, int row);
int		col_is_bad(int *grid, int ***data, int *arr, int row);

#endif
