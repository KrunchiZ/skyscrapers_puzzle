/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_invalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:53:36 by kchiang           #+#    #+#             */
/*   Updated: 2025/08/17 23:59:45 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	arg_is_invalid(int argc, char *argv, t_var *var)
{
	int	i;

	if (argc != 2)
		return (true);
	var->clue_len = ft_strlen(argv);
	var->row_size = (var->clue_len + 1) / 8;
	var->ans_size = var->row_size * var->row_size;
	if ((var->clue_len + 1) % 4)
		return (true);
	i = 0;
	while (i < var->clue_len)
	{
		if (i % 2 && argv[i] != ' ')
			return (true);
		if (i % 2 == 0 && (argv[i] < '1' || argv[i] > var->row_size + '0'))
			return (true);
		i++;
	}
	return (false);
}
