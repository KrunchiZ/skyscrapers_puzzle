/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:45:29 by kchiang           #+#    #+#             */
/*   Updated: 2025/08/15 11:04:27 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	reset_one_row(t_var *var, int *answer);
static int	is_fullrow(int pos, int row_size);
static int	is_fullcol(int pos, int row_size);

void	check_clue(t_var *var, int *answer)
{
	if ((!is_fullrow(var->pos, var->row_size) && exceed_left_clue(answer, *var))
		|| (is_fullrow(var->pos, var->row_size) && row_is_bad(answer, *var)))
	{
		answer[--var->pos] = 0;
		var->n = answer[--var->pos] + 1;
	}
	else if ((var->pos > var->row_size && exceed_top_clue(answer, *var))
		|| (is_fullcol(var->pos, var->row_size) && col_is_bad(answer, *var)))
		reset_one_row(var, answer);
	else
		var->n = 1;
	return ;
}

static void	reset_one_row(t_var *var, int *answer)
{
	int	i;

	i = 0;
	while (i++ < var->row_size)
		answer[--var->pos] = 0;
	var->pos--;
	var->n = answer[var->pos] + 1;
}

static int	is_fullrow(int pos, int row_size)
{
	return (pos % row_size == 0);
}

static int	is_fullcol(int pos, int row_size)
{
	return (pos > row_size * (row_size - 1));
}
