/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_invalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:53:36 by kchiang           #+#    #+#             */
/*   Updated: 2025/09/23 01:44:48 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	arg_is_invalid(int argc, char *argv, int *clue_len, int *n)
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
