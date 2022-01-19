/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:28:35 by emende            #+#    #+#             */
/*   Updated: 2022/01/19 13:09:32 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	validate_tetrimino(const char **map)
{
	int	count;
	int	row;
	int	col;

	count = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '#' && row > 0 && map[row - 1][col] == '#')
				count++;
			if (map[row][col] == '#' && col > 0 && map[row][col - 1] == '#')
				count++;
			if (map[row][col] == '#' && row < 3 && map[row + 1][col] == '#')
				count++;
			if (map[row][col] == '#' && col < 3 && map[row][col + 1] == '#')
				count++;
			col++;
		}
		row++;
	}
	return (count);
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
		if (col != 4)
			return (-1);
		row++;
	}
	if (hash != 4 || row != 4)
		return (-1);
	return (0);
}

static char	**fill_map(const int fd)
{
	char	**map;
	char	*line;
	int		i;

	map = (char **)malloc(sizeof(*map) * 5);
	if (map == NULL)
		exit(0);
	i = 0;
	while (i < 4)
	{
		if (get_next_line(fd, &line) < 1 && i == 0)
			return (NULL);
		if (*line == '\0')
			exit(0);
		map[i++] = line;
	}
	get_next_line(fd, &line);
	if (*line != '\0')
	{
		free(line);
		exit(0);
	}
	map[i] = NULL;
	free(line);
	return (map);
}

static void *find_coordinates(const char **map)
{
	int	*array;
	int	row;
	int	col;
	int	count;

	array = (int *)malloc(sizeof(*arrey) * 8);
	if (array == NULL)
		exit(0);
	row = 0;
	count = 0;
	while(map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '#')
			{
				array[count++] = row;
				array[count++] = col;
			}
			col++
		}
		row++
	}
}

void	fetcher(const int fd)
{
	char	**temp;

	while (1)
	{
		temp = fill_map(fd);
		if (temp == NULL)
			break ;
		if (validate_map((const char **) temp) < 0)
			exit(0);
		print_map(temp);
		ft_putnbr(validate_tetrimino((const char **) temp));
		if (validate_tetrimino((const char **) temp) < 6)
			exit(0);
		ft_putchar('\n');
		free_map(temp);
	}
}
