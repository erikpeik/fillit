/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colored_print_result.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:59:03 by altikka           #+#    #+#             */
/*   Updated: 2022/02/04 14:35:43 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void	put_even_more_emoji(int num)
{
	if (num == 22)
		ft_putstr("\xF0\x9F\x8C\xA0");
	else if (num == 23)
		ft_putstr("\xF0\x9F\x91\xBE");
	else if (num == 24)
		ft_putstr("\xF0\x9F\x92\xBF");
	else if (num == 25)
		ft_putstr("\xF0\x9F\x8E\xBE");
	else if (num == 26)
		ft_putstr("\xF0\x9F\x93\xAE");
}

static void	put_more_emoji(int num)
{
	if (num == 11)
		ft_putstr("\xF0\x9F\x8E\x86");
	else if (num == 12)
		ft_putstr("\xF0\x9F\x90\xA6");
	else if (num == 13)
		ft_putstr("\xE2\x9D\x8E");
	else if (num == 14)
		ft_putstr("\xF0\x9F\x94\xB4");
	else if (num == 15)
		ft_putstr("\xF0\x9F\x88\xB8");
	else if (num == 16)
		ft_putstr("\xF0\x9F\x97\xBE");
	else if (num == 17)
		ft_putstr("\xF0\x9F\x92\x9F");
	else if (num == 18)
		ft_putstr("\xF0\x9F\x86\x97");
	else if (num == 19)
		ft_putstr("\xF0\x9F\x93\x97");
	else if (num == 20)
		ft_putstr("\xF0\x9F\x8E\x92");
	else if (num == 21)
		ft_putstr("\xF0\x9F\x8C\x87");
	else
		put_even_more_emoji(num);
}

static void	put_emoji(int num)
{
	if (num == 0)
		ft_putstr("\xE2\x97\xBE");
	else if (num == 1)
		ft_putstr("\xE2\x9C\x85");
	else if (num == 2)
		ft_putstr("\xF0\x9F\x86\x98");
	else if (num == 3)
		ft_putstr("\xF0\x9F\x86\x9A");
	else if (num == 4)
		ft_putstr("\xF0\x9F\x9B\x82");
	else if (num == 5)
		ft_putstr("\xF0\x9F\x86\x94");
	else if (num == 6)
		ft_putstr("\xF0\x9F\x9A\xAE");
	else if (num == 7)
		ft_putstr("\xF0\x9F\x8D\x80");
	else if (num == 8)
		ft_putstr("\xF0\x9F\x8D\x84");
	else if (num == 9)
		ft_putstr("\xF0\x9F\x8D\x8A");
	else if (num == 10)
		ft_putstr("\xF0\x9F\x8C\x80");
	else
		put_more_emoji(num);
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
			put_emoji(map[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
