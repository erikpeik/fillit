/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:40:02 by altikka           #+#    #+#             */
/*   Updated: 2022/01/24 14:41:15 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

 void	free_map(void **ar, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
	ar = NULL;
}

int	**create_map(size_t size)
{
	int		**map;
	size_t	row;

	map = (int **)malloc(sizeof(*map) * (size));
	if (map == NULL)
		return (NULL);
	row = 0;
	while (row < size)
	{
		map[row] = (int *)malloc(sizeof(**map) * (size));
		if (map[row] == NULL)
		{
			free_map((void **) map, size);
			return (NULL);
		}
		ft_memset(map[row], 0, sizeof(**map) * (size));
		row++;
	}
	return (map);
}
