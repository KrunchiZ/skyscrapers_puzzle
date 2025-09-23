/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:59:53 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 14:01:16 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	*init_grid(char *argv);
static void	print_grid(int *grid, int **set, int n);
static int	arg_is_invalid(int argc, char *argv, int *clue_len, int *n);

int	main(int argc, char *argv[])
{
	int		*grid;
	int		**data[2];
	int		set_size;
	int		n;

	grid = NULL;
	data[CLUE] = NULL;
	data[SET] = NULL;
	if (arg_is_invalid(argc, argv[1], &n))
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		set_size = ft_factorial(n);
		grid = init_grid(argv[1], n);
		data[CLUE] = parse_clue(argv[1], clue_len, n);
		data[SET] = set_permutation(n, set_size);
		if (!grid || !data[CLUE] || !data[SET])
			write(STDERR_FILENO, "Error\n", 6);
		else if (solve_puzzle(grid, data, n, set_size) == SUCCESS)
			print_grid(grid, data[SET], n);
		else
			write(STDERR_FILENO, "Error\n", 6);
	}
	free_2darray(data[CLUE], SIDE_NBR);
	return (free(grid), free_set(data[SET], set_size), EXIT_SUCCESS);
/*	time_t	start;
	time_t	end;
	time(&start);
	printf("\n%dx%d runtime: %.0f seconds.\n",
		n, n, difftime(time(&end), start));
*/
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

static int	**init_grid(char *argv, int n)
{
	int	i;
	int	*grid;

	grid = malloc(n * sizeof(int));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < n)
		grid[i++] = NULL;
	return (grid);
}
