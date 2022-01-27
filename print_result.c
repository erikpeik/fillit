/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:59:03 by altikka           #+#    #+#             */
/*   Updated: 2022/01/27 15:56:20 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	print_result(int **map, size_t n)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			if (map[row][col] == 0)
				ft_putchar('.');
			else
				ft_putchar((char )(map[row][col] + 64));
			col++;
		}
		ft_putchar('\n');
		row++;
	}
//	ft_putchar('\n');
}
