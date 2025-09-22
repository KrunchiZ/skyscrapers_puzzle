/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 00:55:00 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 00:59:24 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIDE_NBR 4

static int	**init_clue(int row_size);

int	**parse_clue(char *argv, int clue_len, int n)
{
	int	i;
	int	row;
	int	col;
	int	**clue;

	clue = init_clue(n);
	if (!clue)
		return (NULL);
	i = 0;
	row = 0;
	col = 0;
	while (i < clue_len)
	{
		if (i % 2 == 0)
			clue[row][col++] = argv[i] - '0';
		if (col == n)
		{
			row++;
			col = 0;
		}
		i++;
	}
	return (clue);
}

static int	**init_clue(int n)
{
	int	**clue;
	int	row;

	clue = (int **)malloc(SIDE_NBR * sizeof(int *));
	if (!clue)
		return (NULL);
	row = 0;
	while (row < n)
	{
		clue[row] = (int *)malloc(n * sizeof(int));
		if (!clue[row])
		{
			while (row >= 0)
				free(clue[row--]);
			free(clue);
			return (NULL);
		}
		row++;
	}
	return (clue);
}
