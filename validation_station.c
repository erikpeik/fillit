/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_station.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:59:48 by altikka           #+#    #+#             */
/*   Updated: 2022/01/21 17:05:06 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	validate_tetrimino(const char **map)
{
	int	touch;
	int	row;
	int	col;

	touch = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '#' && row > 0 && map[row - 1][col] == '#')
				touch++;
			if (map[row][col] == '#' && col > 0 && map[row][col - 1] == '#')
				touch++;
			if (map[row][col] == '#' && row < 3 && map[row + 1][col] == '#')
				touch++;
			if (map[row][col] == '#' && col < 3 && map[row][col + 1] == '#')
				touch++;
			col++;
		}
		row++;
	}
	return (touch);
}

int	validate_map(const char **map)
{
	int	row;
	int	col;
	int	hash;

	hash = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '#')
				hash++;
			else if (map[row][col] != '.')
				return (-1);
			col++;
		}
		if (col != FOUR)
			return (-1);
		row++;
	}
	if (hash != FOUR || row != FOUR)
		return (-1);
	return (0);
}
