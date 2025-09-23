/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:12:18 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 13:19:52 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	value_is_unique(int *comb, int value, int col);
static void	intcpy(int **set, int *comb, int n);

void	generate_comb(int **set, int *comb, int n, int col)
{
	int	value;

	if (col == n)
	{
		intcpy(set, comb, n]);
		return ;
	}
	value = 0;
	while (value < n)
	{
		if (value_is_unique(comb, value, col))
		{
			comb[col] = value;
			generate_comb(set, comb, n, col + 1);
		}
		value++;
	}
	return ;
}

static void	intcpy(int **set, int *comb, int n)
{
	int	i;
	int	row;

	row = 0;
	while (set[row][0] != 0)
		row++;
	i = 0;
	while (i < n)
	{
		set[row][i] = comb[i];
		i++;
	}
	return ;
}

static int	value_is_unique(int *comb, int value, int col)
{
	int	i;

	i = 0;
	while (i <= col)
	{
		if (comb[i++] == value)
			return (false);
	}
	return (true);
}
