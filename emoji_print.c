/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colored_print_result.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:59:03 by altikka           #+#    #+#             */
/*   Updated: 2022/02/04 12:02:08 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	put_emoji(int num)
{
	if (num == 1)
		ft_putstr("\xE2\x9C\x85");
	if (num == 2)
		ft_putstr("\xF0\x9F\x86\x9A");
	if (num == 3)
		ft_putstr("\xF0\x9F\x86\x98");
	if (num == 4)
		ft_putstr("\xF0\x9F\x86\x94");
	if (num == 5)
		ft_putstr("\xF0\x9F\x9A\xAE");
	if (num == 6)
		ft_putstr("\xF0\x9F\x9A\xBE");
	if (num == 7)
		ft_putstr("\xF0\x9F\x92\x9F");
}

void	print_result(const int **map, size_t n)
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
				ft_putstr("\xE2\x9C\xA8");
			else
				put_emoji(map[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
