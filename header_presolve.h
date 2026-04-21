/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_presolve.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:57:49 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 03:18:51 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

/* STUFF FOR SRC VERSION */
typedef struct s_var
{
	int	mask[81];
	int	**clue;
	int	row_size;
	int	ans_size;
	int	n;
	int	pos;
	int	clue_len;
}		t_var;

int		arg_is_invalid(int argc, char *argv, t_var *var);
int		**parse_clue(char *argv, t_var var);
void	pre_solve(int *answer, t_var *var);
int		solve_puzzle(int *answer, t_var var);
void	check_clue(t_var *var, int *answer);
int		exceed_left_clue(int *answer, t_var var);
int		exceed_top_clue(int *answer, t_var var);
int		row_is_bad(int *answer, t_var var);
int		col_is_bad(int *answer, t_var var);

#endif
