/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:17:19 by altikka           #+#    #+#             */
/*   Updated: 2022/01/25 15:18:30 by altikka          ###   ########.fr       */
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
		if (map[col][row] != 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

void	solver(t_block *tet, int ***map, size_t size)
{
	int	ret;

	ret = does_it_fit(tet, *map, size);
	ft_putstr("ret: ");
	ft_putnbr(ret);
	ft_putstr("\nsize: ");
	ft_putnbr((int) size);
	ft_putchar('\n');
	if (ret == -121 && tet->n == 1)
	{
		*map = recreate_map(*map, size + 1);
		solver(tet, map, size + 1);
	}
}
