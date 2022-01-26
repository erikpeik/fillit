/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:17:19 by altikka           #+#    #+#             */
/*   Updated: 2022/01/27 00:37:29 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

#include <stdio.h> // REMOVE

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

int	solver(t_block *tet, int ***map, size_t *size)
{
	int	ret;

	if (tet == NULL)
		return (1);
	ret = does_it_fit(tet, *map, *size);
	while (ret != -121)
	{
		if (ret == 0)
			move_right(tet->pos);
		if (ret == -120)
			move_left_and_down(tet->pos);
		if (ret == 1)
		{
			place(tet, map, tet->n);
			if (solver(tet->next, map, size) == 1)
				return (1);
			else
			{
				place(tet, map, 0);
				move_right(tet->pos);
			}
		}
		ret = does_it_fit(tet, *map, *size);
	}
	push_top_left(tet->pos);
	return (0);
}

/*
int	solver(t_block *tet, int ***map, size_t *size)
{
	int	ret;

	if (tet == NULL)
		return (1);
	ret = does_it_fit(tet, *map, *size);
	while (ret != 1 && ret != -121)
	{
		if (ret == 0)
			move_right(tet->pos);
		if (ret == -120)
			move_left_and_down(tet->pos);
		ret = does_it_fit(tet, *map, *size);
	}
	if (ret == 1)
	{
		ft_putstr("PLACE: ");
			ft_putchar((char)( tet->n + 64));
			ft_putchar('\n');
		place(tet, map, tet->n);
		print_result(*map, *size);
		if (solver(tet->next, map, size) == 1)
			return (1);
		else
		{
			ft_putstr("REMOVE: ");
			ft_putchar((char)( tet->n + 64));
			ft_putchar('\n');
			place(tet, map, 0);
			move_right(tet->pos);
			if (solver(tet, map, size) == 1)
				return (1);
		}
	}
	return (0);
} */

/*int	solver(t_block *tet, int ***map, size_t *size)
{
	int	ret;

	if (tet == NULL)	//the end
		return (1);
	ret = does_it_fit(tet, *map, *size);
	if (ret == 0)
	{
		move_right(tet->pos);
		return (solver(tet, map, size));
	}
	if (ret == -120)
	{
		move_left_and_down(tet->pos);
		return (solver(tet, map, size));
	}
	if (ret == -121 && tet->n == 1)
	{
		*map = recreate_map(*map, *size + 1);
		*size += 1;
		return (solver(tet, map, size));
	}
	if (ret == -121)
	{
		return (0);
	}
	if (ret == 1)		//fits -> place
	{
		place(tet, map, tet->n);
		if (solver(tet->next, map, size) == 1)
			return (1);
	}
	place(tet, map, 0);
	return (0);
}*/

/*void	solver(t_block *tet, int ***map, size_t *size)
{
	int	ret;

	ret = does_it_fit(tet, *map, *size);
	ft_putstr("ret: ");
	ft_putnbr(ret);
	ft_putstr("\nsize: ");
	ft_putnbr((int) *size);
	ft_putchar('\n');
	if (ret == -121 && tet->n == 1)
	{
		*map = recreate_map(*map, *size + 1);
//		ft_putendl("----AFTER MALLOCING A BIGGER MAP----");		//
//		system("leaks fillit");									//
		*size += 1;
		solver(tet, map, size);
	}
	if (ret == 1)
		place(tet, map, tet->n);
	print_result(*map, *size);
	place(tet, map, 0);
}*/
