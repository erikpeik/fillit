/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_of_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:40:02 by altikka           #+#    #+#             */
/*   Updated: 2022/02/03 17:29:48 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

size_t	map_min_size(t_block *head)
{
	t_block	*temp;
	size_t	res;

	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	res = (size_t) ft_sqrt((int ) temp->n * FOUR);
	return (res);
}

int	free_map(void **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (1);
}

int	**recreate_map(int **map, size_t size)
{
	int	**new;

	free_map((void **) map, (size - 1));
	new = create_map(size);
	if (new == NULL)
		return (NULL);
	return (new);
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
			free_map((void **) map, row);
			return (NULL);
		}
		ft_memset(map[row], 0, sizeof(**map) * (size));
		row++;
	}
	return (map);
}
