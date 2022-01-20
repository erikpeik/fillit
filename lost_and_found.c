/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_and_found.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:28:35 by emende            #+#    #+#             */
/*   Updated: 2022/01/20 21:59:49 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	push_top_left(int *arr)
{
	int	row_min;
	int	col_min;
	int	i;

	row_min = FOUR;
	col_min = FOUR;
	i = 0;
	while (i < ARR_LEN)
	{
		if (i % 2 == 0 && arr[i] < row_min)
			row_min = arr[i];
		else if (i % 2 != 0 && arr[i] < col_min)
			col_min = arr[i];
		i++;
	}
	i = 0;
	while (i < ARR_LEN)
	{
		if (i % 2 == 0)
			arr[i] -= row_min;
		else
			arr[i] -= col_min;
		i++;
	}
}

static int	*find_coordinates(const char **map)
{
	int	*array;
	int	i;
	int	row;
	int	col;

	array = (int *)malloc(sizeof(*array) * ARR_LEN);
	if (array == NULL)
		exit(1);
	i = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '#')
			{
				array[i++] = row;
				array[i++] = col;
			}
			col++;
		}
		row++;
	}
	return (array);
}

static int	validate_tetrimino(const char **map)
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

static int	validate_map(const char **map)
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

static char	**fill_map(const int fd)
{
	char	**map;
	char	*line;
	int		i;

	map = (char **)malloc(sizeof(*map) * FOUR + 1);
	if (map == NULL)
		exit(2);
	i = 0;
	while (i < FOUR)
	{
		if (get_next_line(fd, &line) < 1 && i == 0)
			return (NULL);
		map[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	get_next_line(fd, &line);
	if (*line != '\0')
	{
		ft_strdel(&line);
		exit(4);
	}
	map[i] = NULL;
	free(line);
	return (map);
}

int	*lost_and_found(const int fd)
{
	char	**map;
	int		*pos;

	map = fill_map(fd);
	if (map == NULL)
		return (NULL);
	print_map(map);
	if (validate_map((const char **) map) < 0)
		exit(5);
	if (validate_tetrimino((const char **) map) < 6)
		exit(6);
	pos = find_coordinates((const char **) map);
	push_top_left(pos);
	free_map(map);
	return (pos);
}
