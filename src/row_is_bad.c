/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_is_bad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:19:01 by kchiang           #+#    #+#             */
/*   Updated: 2025/08/13 13:56:57 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	left_is_bad(int *answer, int *clue, t_var var)
{
	int	max;
	int	seen;
	int	i;

	seen = 0;
	max = 0;
	i = var.row_size;
	while (i >= 1)
	{
		if (answer[var.pos - i] > max)
		{
			seen++;
			max = answer[var.pos - i];
		}
		i--;
	}
	if (seen != clue[(var.pos / var.row_size) - 1])
		return (true);
	return (false);
}

static int	right_is_bad(int *answer, int *clue, t_var var)
{
	int	max;
	int	seen;
	int	i;

	seen = 0;
	max = 0;
	i = 1;
	while (i <= var.row_size)
	{
		if (answer[var.pos - i] > max)
		{
			seen++;
			max = answer[var.pos - i];
		}
		i++;
	}
	if (seen != clue[(var.pos / var.row_size) - 1])
		return (true);
	return (false);
}

int	row_is_bad(int *answer, t_var var)
{
	if (left_is_bad(answer, var.clue[2], var))
		return (true);
	if (right_is_bad(answer, var.clue[3], var))
		return (true);
	return (false);
}

int	exceed_left_clue(int *answer, t_var var)
{
	int	max;
	int	seen;
	int	i;

	seen = 0;
	max = 0;
	i = var.pos / var.row_size * var.row_size;
	while (i < var.pos)
	{
		if (answer[i] > max)
		{
			seen++;
			max = answer[i];
		}
		i++;
	}
	if (seen > var.clue[2][(var.pos - 1) / var.row_size])
		return (true);
	return (false);
}
