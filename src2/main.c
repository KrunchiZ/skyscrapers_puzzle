/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:59:53 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 01:49:22 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	*init_grid(char *argv);
static void	print_grid(int **grid, int n);

int	main(int argc, char *argv[])
{
	int		**grid;
	int		**clue;
	int		**set;
	int		set_size;
	int		n;

	grid = NULL;
	if (arg_is_invalid(argc, argv[1], &n))
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		grid = init_grid(argv[1], n);
		clue = parse_clue(argv[1], clue_len, n);
		set_size = ft_factorial(n);
		set = get_permutation(n, set_size);
		if (!var.clue || !answer || !set)
			write(STDERR_FILENO, "Error\n", 6);
		else if (solve_puzzle(grid, set, n))
			print_grid(grid, n);
		else
			write(STDERR_FILENO, "Error\n", 6);
	}
	free_2darray(clue, SIDE_NBR);
	return (free_2darray(grid, n), free_set(set, set_size), EXIT_SUCCESS);
/*	time_t	start;
	time_t	end;
	time(&start);
	printf("\n%dx%d runtime: %.0f seconds.\n",
		n, n, difftime(time(&end), start));
*/
}

static int	**init_grid(char *argv, int n)
{
	int	i;
	int	**grid;

	grid = (int **)malloc(n * sizeof(int *));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < size)
		grid[i++] = NULL;
	return (grid);
}

static void	print_grid(int **grid, int n)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			c = grid[row][col++] + '0';
			write(STDOUT_FILENO, &c, 1);
			if (col == n)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
		}
		row++;
	}
	return ;
}
