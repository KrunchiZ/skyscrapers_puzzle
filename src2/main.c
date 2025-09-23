/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:59:53 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 17:43:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static void	init_grid_data(int **grid, int ***data);
static int	*init_grid(int n);
static void	print_grid(int *grid, int **set, int n);
static int	arg_is_invalid(int argc, char *argv, int *clue_len, int *n);

int	main(int argc, char *argv[])
{
	time_t	start;
	time_t	end;
	int		*grid;
	int		**data[2];
	int		set_size;
	int		clue_len;
	int		n;

	time(&start);
	init_grid_data(&grid, data);
	if (arg_is_invalid(argc, argv[1], &clue_len, &n))
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		set_size = ft_factorial(n);
		grid = init_grid(n);
		data[CLUE] = parse_clue(argv[1], clue_len, n);
		data[SET] = set_permutation(n, set_size);
		if (!grid || !data[CLUE] || !data[SET])
			write(STDERR_FILENO, "Error\n", 6);
		else if (solve_puzzle(grid, data, n, set_size) == SUCCESS)
			print_grid(grid, data[SET], n);
		else
			write(STDERR_FILENO, "Error\n", 6);
		free_set(data[SET], set_size);
	}
	printf("\n%dx%d runtime: %.0f seconds.\n",
		n, n, difftime(time(&end), start));
	return (free(grid), free_2darray(data[CLUE], SIDE_NBR), EXIT_SUCCESS);
}

static void	init_grid_data(int **grid, int ***data)
{
	*grid = NULL;
	data[CLUE] = NULL;
	data[SET] = NULL;
	return ;
}

static void	print_grid(int *grid, int **set, int n)
{
	int		i;
	int		col;
	char	c;

	i = 0;
	while (i < n)
	{
		col = 0;
		while (col < n)
		{
			c = set[grid[i]][col++] + '0';
			write(STDOUT_FILENO, &c, 1);
			if (col == n)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
		}
		i++;
	}
	return ;
}

static int	arg_is_invalid(int argc, char *argv, int *clue_len, int *n)
{
	int	i;

	if (argc != 2)
		return (true);
	*clue_len = ft_strlen(argv);
	if ((*clue_len + 1) % 4)
		return (true);
	*n = (*clue_len + 1) / 8;
	i = 0;
	while (i < *clue_len)
	{
		if (i % 2 && argv[i] != ' ')
			return (true);
		if (i % 2 == 0 && (argv[i] < '1' || argv[i] > *n + '0'))
			return (true);
		i++;
	}
	return (false);
}

static int	*init_grid(int n)
{
	int	i;
	int	*grid;

	grid = malloc(n * sizeof(int));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < n)
		grid[i++] = 0;
	return (grid);
}
