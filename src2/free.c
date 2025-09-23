/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 01:08:33 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 13:40:45 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_2darray(char **arr, int n)
{
	int	row;

	if (arr)
	{
		row = 0;
		while (row < n)
			free(arr[row++]);
	}
	free(arr);
	return ;
}

void	free_set(char **arr, int n)
{
	int	row;

	if (arr)
	{
		row = 0;
		while (row < n)
			free(arr[row++]);
	}
	free(arr);
	return ;
}
