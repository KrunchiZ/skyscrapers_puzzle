/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:50:11 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 16:37:57 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	generate_grid(int *grid, int ***data, int *limit, int row);
static int	set_is_valid(int *grid, int ***data, int *arr, int row);
static int	col_has_dup(int *grid, int ***data, int *arr, int row);
static int	exceed_top_clue(int *grid, int ***data, int *arr, int row);

int	solve_puzzle(int *grid, int ***data, int n, int set_size);
{
	int	arr[3];
	int	starting_row;

	starting_row = 0;
	arr[GRID_SIZE] = n;
	arr[SET_SIZE] = set_size;
	return (generate_grid(grid, data, arr, starting_row));
}

static int	generate_grid(int *grid, int ***data, int *arr, int row)
{
	int	i;

	if (row == arr[GRID_SIZE])
		return (SUCCESS);
	i = 0;
	while (i < arr[SET_SIZE])
	{
		grid[row] = i;
		if (set_is_valid(grid, data, arr, row))
			&& (generate_grid(grid, data, arr, row + 1) == SUCCESS))
			return (SUCCESS);
		else
			grid[row] = 0;
		i++;
	}
	return (FAILURE);
}

static int	set_is_valid(int *grid, int ***data, int *arr, int row)
{
	if (row > 0 && col_has_dup(grid, data, arr, row))
		return (false);
	if (row > 0 && exceed_top_clue(grid, data, arr, row))
		return (false);
	if (row_is_bad(grid, data, arr, row))
		return (false);
	if (row + 1 == arr[GRID_SIZE] && col_is_bad(grid, data, arr, row))
		return (false);
	return (true);
}

static int	col_has_dup(int *grid, int ***data, int *arr, int row)
{
	int	i;
	int	col;
	int	**set;

	set = data[SET];
	i = 0;
	while (i < row)
	{
		col = 0;
		while (col < arr[GRID_SIZE])
		{
			if (set[grid[i]][col] == set[grid[row]][col])
				return (true);
			col++;
		}
		i++;
	}
	return (false);
}

static int	exceed_top_clue(int *grid, int ***data, int *arr, int row)
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
		while (i <= row)
		{
			if (data[SET][grid[i]][col] > max)
			{
				seen++;
				max = data[SET][grid[i]][col];
			}
			i++;
		}
		if (seen > data[CLUE][TOP][col])
			return (true);
		col++;
	}
	return (false);
}
