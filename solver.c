/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:17:19 by altikka           #+#    #+#             */
/*   Updated: 2022/02/02 17:59:24 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int	does_it_fit(t_block *tet, int **map, size_t size)
{
	size_t	i;
	size_t	row;
	size_t	col;

	i = 0;
	while (i < ARR_LEN)
	{
		row = (size_t)(tet->pos)[i];
		if (row >= size)
			return (-121);
		col = (size_t)(tet->pos)[i + 1];
		if (col >= size)
			return (-120);
		if (map[row][col] != 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

static void	bigger_map(t_block *tet, int ***map, size_t *size)
{
	*map = recreate_map(*map, *size + 1);
	if (*map == NULL && err_blocks(tet))
		exit(1);
	*size += 1;
}

int	solver(t_block *tet, int ***map, size_t *size, int ret)
{
	if (tet == NULL)
		return (1);
	ret = does_it_fit(tet, *map, *size);
	while (ret != -121)
	{
		if (ret == 1)
		{
			place(tet, map, tet->n);
			if (solver(tet->next, map, size, ret) == 1)
				return (1);
			place(tet, map, 0);
		}
		if (ret != -120)
			move_right(tet->pos);
		else
			move_left_and_down(tet->pos, (int )*size);
		ret = does_it_fit(tet, *map, *size);
	}
	move_top_left(tet->pos, (int )*size);
	if (ret == -121 && tet->n == 1)
	{
		bigger_map(tet, map, size);
		solver(tet, map, size, ret);
	}
	return (0);
}
