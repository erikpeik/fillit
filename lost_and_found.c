/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_and_found.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:28:35 by emende            #+#    #+#             */
/*   Updated: 2022/02/07 15:48:03 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	*find_coordinates(const char **map)
{
	int	*array;
	int	i;
	int	row;
	int	col;

	array = (int *)malloc(sizeof(*array) * ARR_LEN);
	if (array == NULL)
		return (NULL);
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

static int	get_fifth_line(const int fd, char ***map)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (line == NULL || ret < 0)
	{
		free_map((void **) *map, FOUR);
		return (-1);
	}
	if (ret == 0 && *line == '\0')
	{
		ft_strdel(&line);
		return (0);
	}
	if (*line != '\0')
	{
		free_map((void **) *map, FOUR);
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (1);
}

static int	fill_map(const int fd, char ***map)
{
	char	*line;
	size_t	i;
	int		ret;

	(*map) = (char **)malloc(sizeof(*map) * (FOUR + 1));
	if ((*map) == NULL)
		return (-1);
	i = 0;
	while (i < FOUR)
	{
		ret = get_next_line(fd, &line);
		if (ret < 1 && free_map((void **) *map, i))
		{
			ft_strdel(&line);
			return (-1);
		}
		(*map)[i] = ft_strdup(line);
		ft_strdel(&line);
		if ((*map)[i] == NULL && free_map((void **) *map, i))
			return (-1);
		i++;
	}
	ret = get_fifth_line(fd, map);
	(*map)[i] = NULL;
	return (ret);
}

int	lost_and_found(const int fd, int **pos)
{
	char	**map;
	int		ret;

	ret = fill_map(fd, &map);
	if (ret == -1)
		return (ret);
	if (validate_map((const char **) map) < 0)
	{
		free_map((void **) map, FOUR);
		return (-1);
	}
	if (validate_tetrimino((const char **) map) < 6)
	{
		free_map((void **) map, FOUR);
		return (-1);
	}
	(*pos) = find_coordinates((const char **) map);
	if (*pos == NULL)
	{
		free_map((void **) map, FOUR);
		return (-1);
	}
	move_top_left((*pos), FOUR);
	free_map((void **) map, FOUR);
	return (ret);
}
