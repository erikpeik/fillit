/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:49:24 by altikka           #+#    #+#             */
/*   Updated: 2022/01/20 15:57:08 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	print_int_array(int *arr)
{
	int	i;

	i = 0;
	while (i < ARR_LEN)
		ft_putnbr(arr[i++]);
}

void	print_struct(t_block *head)
{
	t_block	*temp;

	temp = head;
	ft_putendl("Printing attributes tetriminos...");
	while (temp != NULL)
	{
		ft_putnbr((int ) temp->n);
		ft_putstr(":	");
		print_int_array(temp->pos);
		ft_putstr("w: ");
		ft_putnbr(temp->width);
		ft_putstr(" h: ");
		ft_putnbr(temp->height);
		ft_putchar('\n');
		temp = temp->next;
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}
