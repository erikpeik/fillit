/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & ememde <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/01/14 18:34:20 by altikka          ###   ########.fr       */
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
}

static int	validate_map(char **map)
{
	int	row;
	int	col;
	int	dot;
	int	hash;

	dot = 0;
	hash = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '.')
				dot++;
			else if (map[row][col] == '#')
				hash++;
			else
				return (-1);
			col++;
		}
		if (col != 4 && row % 4 != 0)
			return (-1);
		row++;
	}
	if (hash != 4 || dot != 12)
		return (-1);
	return (0);
}

static char	**fill_map(const int fd)
{
	char	**map;
	char	*line;
	int		i;
	int		res;

	map = (char **)malloc(sizeof(*map) * 5);
	i = 0;
	while (i < 4)
	{
		res = get_next_line(fd, &line);
		map[i] = line;
		i++;
	}
	res = get_next_line(fd, &line);
	if (*line != '\0')
		return (NULL);
	map[i] = ft_strnew(0);
	return (map);
}

static int	gather_and_validate(const int fd)
{
	char	***field_of_maps;
	int		i;

	i = 0;
	field_of_maps = (char ***)malloc(sizeof(*field_of_maps) * 5);
	while (i < 4)
	{
		field_of_maps[i] = fill_map(fd);
		i++;
	}	
	field_of_maps[i] = NULL;
	i = 0;
	while (field_of_maps[i])
	{
		print_map(field_of_maps[i]);
		if (validate_map(field_of_maps[i]) == 0)
			ft_putendl("MAP OK");
		else
			ft_putendl("MAP FAIL");
		i++;
	}
	return (0);
}

int	fillit(const int fd)
{
	gather_and_validate(fd);
	return (0);
}
