/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_permutation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 01:48:53 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 13:25:23 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	reset_comb(int *comb, int n);
static int	**init_set(int n, int set_size);

int	**set_permutation(int n, int set_size)
{
	int	**set;
	int	*comb;
	int	limit[2];

	comb = malloc(n * sizeof(int));
	if (!comb)
		return (NULL);
	reset_comb(comb, n);
	set = init_set(n, set_size);
	if (!set)
		return (free(comb), NULL);
	generate_comb(set, comb, n, 0);
	return (free(comb), set);
}

static void	reset_comb(int *comb, int n)
{
	int	i;

	i = 0;
	while (i < n)
		comb[i++] = 0;
	return ;
}

static int	**init_set(int n, int set_size)
{
	int	**set;
	int	i;

	set = malloc(set_size * sizeof(int *));
	i = 0;
	while (i < set_size)
	{
		set[i] = malloc(n * sizeof(int));
		if (!set[i])
		{
			while (i >= 0)
				free(set[i--]);
			free(set);
			return (NULL);
		}
		set[i][0] = 0;
		i++;
	}
	return (set);
}
