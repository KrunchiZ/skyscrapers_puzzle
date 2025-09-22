/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:57:49 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 01:50:15 by kchiang          ###   ########.fr       */
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

/* STUFF FOR SRC VERSION
typedef struct s_var
{
	int	row_size;
	int	ans_size;
	int	n;
	int	pos;
	int	**clue;
	int	clue_len;
}		t_var;

int		arg_is_invalid(int argc, char *argv, t_var *var);
int		**parse_clue(char *argv, t_var var);
int		solve_puzzle(int *answer, t_var var);
void	check_clue(t_var *var, int *answer);
int		exceed_left_clue(int *answer, t_var var);
int		exceed_top_clue(int *answer, t_var var);
int		row_is_bad(int *answer, t_var var);
int		col_is_bad(int *answer, t_var var);
*/

/* STUFF FOR SRC2 VERSION */
void	free_2darray(char **arr, int n);
void	free_set(char **arr, int n);
int		**get_permutation(int n);
int		ft_factorial(int nb);
int		ft_strlen(char *str);

#endif
