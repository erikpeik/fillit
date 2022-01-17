/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & ememde <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/01/17 19:26:01 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
	ft_putchar('\n');
}

static char	**free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (map);
}

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
			if (map[row][col] == '#')
			{
				if (row > 0 && map[row - 1][col] == '#') // up
					count++;
				if (col > 0 && map[row][col - 1] == '#') // left
					count++;
				if (row < 3 && map[row + 1][col] == '#') // down
					count++;
				if (col < 3 && map[row][col + 1] == '#') // right
					count++;
			}
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
	while (map[row] && row < 4)
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
		exit(0); //semi-laiton
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
		exit(0); //semi-laiton
	}
	map[i] = NULL;
	free(line);
	return (map);
}

static void	fetcher(const int fd)
{
	char		**temp;

	while (1)
	{
		temp = fill_map(fd);
		if (temp == NULL)
			break ;
		if (validate_map((const char **) temp) < 0)
			abort(); //semi-laiton
		print_map(temp);
		ft_putnbr(validate_tetrimino((const char **) temp));
		ft_putchar('\n');
		free_map(temp);
	}
}

int	fillit(const int fd)
{
	fetcher(fd);
	return (0);
}
