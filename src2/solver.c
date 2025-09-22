/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:50:11 by kchiang           #+#    #+#             */
/*   Updated: 2025/08/15 11:14:10 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_unique(t_var var, int *answer);

int	solve_puzzle(int *answer, t_var var)
{
	var.n = 1;
	while (var.n <= var.row_size + 1 && var.pos < var.ans_size)
	{
		if (var.n <= var.row_size && is_unique(var, answer))
		{
			answer[var.pos++] = var.n++;
			check_clue(&var, answer);
		}
		else
			var.n++;
		if (var.n > var.row_size && var.pos > 0)
		{
			answer[var.pos--] = 0;
			var.n = answer[var.pos] + 1;
		}
		if (var.n > var.row_size && var.pos == 0)
			return (false);
	}
	return (true);
}

static int	is_unique(t_var var, int *answer)
{
	int	i;

	i = var.pos;
	while (i >= (var.pos / var.row_size * var.row_size))
	{
		if (var.n == answer[i])
			return (false);
		i--;
	}
	i = var.pos;
	while (i >= 0)
	{
		if (var.n == answer[i])
			return (false);
		i -= var.row_size;
	}
	return (true);
}
