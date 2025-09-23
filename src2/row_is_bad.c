/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_is_bad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:19:01 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 16:38:58 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	left_is_bad(int *grid, int ***data, int *arr, int row);
static int	right_is_bad(int *grid, int ***data, int *arr, int row);

int	row_is_bad(int *grid, int ***data, int *arr, int row)
{
	if (left_is_bad(grid, data, arr, row))
		return (true);
	if (right_is_bad(grid, data, arr, row))
		return (true);
	return (false);
}

static int	left_is_bad(int *grid, int ***data, int *arr, int row)
{
	int	max;
	int	seen;
	int	col;

	seen = 0;
	max = 0;
	col = 0;
	while (col < arr[GRID_SIZE])
	{
		if (data[SET][grid[row]][col] > max)
		{
			seen++;
			max = data[SET][grid[row]][col];
		}
		col++;
	}
	if (seen != data[CLUE][LEFT][row])
		return (true);
	return (false);
}

static int	right_is_bad(int *grid, int ***data, int *arr, int row)
{
	int	max;
	int	seen;
	int	col;

	seen = 0;
	max = 0;
	col = arr[GRID_SIZE] - 1;
	while (col >= 0)
	{
		if (data[SET][grid[row]][col] > max)
		{
			seen++;
			max = data[SET][grid[row]][col];
		}
		col--;
	}
	if (seen != data[CLUE][RIGHT][row])
		return (true);
	return (false);
}
