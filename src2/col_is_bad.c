/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_is_bad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:19:01 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 14:36:41 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	top_is_bad(int *answer, int *clue, t_var var);
static int	bottom_is_bad(int *answer, int *clue, t_var var);

int	exceed_top_clue(int *grid, int ***data, int *arr, int row)
{
	int	max;
	int	seen;
	int	i;
	int col;

	col = 0;
	while (col < arr[GRID_SIZE])
	{
		seen = 0;
		max = 0;
		i = 0;
		while (i < row)
		{
			if (data[SET][grid[i]][col] > max)
			{
				seen++;
				max = data[SET][grid[i]][col];
			}
			i++;
		}
		if (seen > data[CLUE][0][col])
			return (true);
		col++;
	}
	return (false);
}

int	col_is_bad(int *answer, t_var var)
{
	var.pos--;
	if (top_is_bad(answer, var.clue[0], var))
		return (true);
	if (bottom_is_bad(answer, var.clue[1], var))
		return (true);
	return (false);
}

static int	top_is_bad(int *answer, int *clue, t_var var)
{
	int	max;
	int	seen;
	int	i;

	seen = 0;
	max = 0;
	i = var.row_size - 1;
	while (i >= 0)
	{
		if (answer[var.pos - (i * var.row_size)] > max)
		{
			seen++;
			max = answer[var.pos - (i * var.row_size)];
		}
		i--;
	}
	if (seen != clue[var.pos - var.row_size * (var.row_size - 1)])
		return (true);
	return (false);
}

static int	bottom_is_bad(int *answer, int *clue, t_var var)
{
	int	max;
	int	seen;
	int	i;

	seen = 0;
	max = 0;
	i = 0;
	while (i <= var.row_size - 1)
	{
		if (answer[var.pos - (i * var.row_size)] > max)
		{
			seen++;
			max = answer[var.pos - (i * var.row_size)];
		}
		i++;
	}
	if (seen != clue[var.pos - var.row_size * (var.row_size - 1)])
		return (true);
	return (false);
}
