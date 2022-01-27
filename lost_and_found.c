/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_and_found.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:28:35 by emende            #+#    #+#             */
/*   Updated: 2022/01/27 09:25:10 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	move_top_left(int *arr)
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

static void	get_fifth_line(const int fd)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret < 0)
		exit(7);
	if (*line != '\0')
	{
		ft_strdel(&line);
		exit(4);
	}
	free(line);
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
		{
			free(map);
			return (NULL);
		}
		map[i] = ft_strdup(line);
		if (map[i] == NULL)
			exit(3);
		ft_strdel(&line);
		i++;
	}
	get_fifth_line(fd);
	map[i] = NULL;
	return (map);
}

int	*lost_and_found(const int fd)
{
	char	**map;
	int		*pos;

	map = fill_map(fd);
	if (map == NULL)
		return (NULL);
//	print_map(map);
	if (validate_map((const char **) map) < 0)
		exit(5);
	if (validate_tetrimino((const char **) map) < 6)
		exit(6);
	pos = find_coordinates((const char **) map);
	move_top_left(pos);
	free_map((void **) map, FOUR);
	return (pos);
}
