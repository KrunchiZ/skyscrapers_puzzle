/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_is_bad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:19:01 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 17:05:18 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	top_is_bad(int *grid, int ***data, int *arr, int row);
static int	bottom_is_bad(int *grid, int ***data, int *arr, int row);

int	col_is_bad(int *grid, int ***data, int *arr, int row)
{
	if (top_is_bad(grid, data, arr, row))
		return (true);
	if (bottom_is_bad(grid, data, arr, row))
		return (true);
	return (false);
}

static int	top_is_bad(int *grid, int ***data, int *arr, int row)
{
	int	max;
	int	seen;
	int	col;
	int	i;

	col = 0;
	while (col < arr[GRID_SIZE])
	{
		seen = 0;
		max = 0;
		i = 0;
		while (i <= row)
		{
			if (data[SET][grid[i]][col] > max)
			{
				seen++;
				max = data[SET][grid[i]][col];
			}
			i++;
		}
		if (seen != data[CLUE][TOP][col])
			return (true);
		col++;
	}
	return (false);
}

static int	bottom_is_bad(int *grid, int ***data, int *arr, int row)
{
	int	max;
	int	seen;
	int	col;
	int	i;

	col = 0;
	while (col < arr[GRID_SIZE])
	{
		seen = 0;
		max = 0;
		i = row;
		while (i >= 0)
		{
			if (data[SET][grid[i]][col] > max)
			{
				seen++;
				max = data[SET][grid[i]][col];
			}
			i--;
		}
		if (seen != data[CLUE][BOTTOM][col])
			return (true);
		col++;
	}
	return (false);
}
