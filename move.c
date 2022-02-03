/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:13:39 by altikka           #+#    #+#             */
/*   Updated: 2022/02/03 16:41:03 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	place(t_block *tet, int ***map, int n)
{
	int	row;
	int	col;
	int	i;

	i = 0;
	while (i < ARR_LEN)
	{
		row = (tet->pos)[i];
		col = (tet->pos)[i + 1];
		(*map)[row][col] = n;
		i += 2;
	}
}

void	move_left_and_down(int *pos, int max)
{
	int	col_min;
	int	i;

	col_min = max;
	i = 0;
	while (i < ARR_LEN)
	{
		if (i % 2 != 0 && pos[i] < col_min)
			col_min = pos[i];
		i++;
	}
	i = 0;
	while (i < ARR_LEN)
	{
		if (i % 2 != 0)
			pos[i] -= col_min;
		else
			pos[i] += 1;
		i++;
	}
}

void	move_right(int *pos)
{
	int	i;

	i = 0;
	while (i < ARR_LEN)
	{
		if (i % 2 != 0)
			pos[i] += 1;
		i++;
	}
}

void	move_top_left(int *pos, int max)
{
	int	row_min;
	int	col_min;
	int	i;

	row_min = max;
	col_min = max;
	i = 0;
	while (i < ARR_LEN)
	{
		if (i % 2 == 0 && pos[i] < row_min)
			row_min = pos[i];
		else if (i % 2 != 0 && pos[i] < col_min)
			col_min = pos[i];
		i++;
	}
	i = 0;
	while (i < ARR_LEN)
	{
		if (i % 2 == 0)
			pos[i] -= row_min;
		else
			pos[i] -= col_min;
		i++;
	}
}
