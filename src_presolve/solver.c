/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:50:11 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 01:50:04 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_unique(t_var var, int *answer);
static void	set_grid_mask(int *answer, int *mask, int index, int value);
/*
static void	print_answer(int *answer, t_var var)
{
	int		i;
	char	c;

	i = 0;
	while (i < var.ans_size)
	{
		c = answer[i] + '0';
		write(1, &c, 1);
		if ((i + 1) % var.row_size == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return ;
}*/

void	pre_solve(int *answer, t_var *var)
{
	int	i;

	i = -1;
	while (++i < var->row_size)
	{
		if (var->clue[0][i] == 1)
			set_grid_mask(answer, var->mask, i, var->row_size);
		if (var->clue[1][i] == 1)
			set_grid_mask(answer, var->mask,
				var->ans_size - var->row_size + i, var->row_size);
		if (var->clue[2][i] == 1)
			set_grid_mask(answer, var->mask,
				i * var->row_size, var->row_size);
		if (var->clue[3][i] == 1)
			set_grid_mask(answer, var->mask,
				i * var->row_size + var->row_size - 1, var->row_size);
	}
}

static void	set_grid_mask(int *answer, int *mask, int index, int value)
{
	answer[index] = value;
	mask[index] = 1;
}

int	solve_puzzle(int *answer, t_var var)
{
	var.n = 1;
	while (var.n <= var.row_size + 1 && var.pos < var.ans_size)
	{
		//print_answer(answer, var);
		if (var.n <= var.row_size && var.mask[var.pos])
		{
			++var.pos;
			check_clue(&var, answer);
		}
		if (var.n <= var.row_size && is_unique(var, answer))
		{
			answer[var.pos++] = var.n++;
			check_clue(&var, answer);
		}
		else
			var.n++;
		if (var.n > var.row_size && var.pos > 0)
		{
			if (var.mask[var.pos] == 0)
				answer[var.pos] = 0;
			var.n = answer[--var.pos] + 1;
		}
		if (var.n > var.row_size && var.pos == 0)
			return (false);
	}
	return (true);
}

static int	is_unique(t_var var, int *answer)
{
	int	i;

	i = var.pos / var.row_size * var.row_size + var.row_size - 1;
	while (i >= (var.pos / var.row_size * var.row_size))
	{
		if (var.n == answer[i])
			return (false);
		i--;
	}
	i = var.ans_size - var.row_size + var.pos % var.row_size;
	while (i >= 0)
	{
		if (var.n == answer[i])
			return (false);
		i -= var.row_size;
	}
	return (true);
}
