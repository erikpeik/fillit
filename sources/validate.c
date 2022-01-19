/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:28:35 by emende            #+#    #+#             */
/*   Updated: 2022/01/19 18:58:42 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	top_left(int *arr)
{
	int	x_min;
	int	y_min;
	int	i;

	x_min = 4;
	y_min = 4;
	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0 && arr[i] < x_min)
			x_min = arr[i];
		else if (i % 2 != 0 && arr[i] < y_min)
			y_min = arr[i];
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
			arr[i] -= x_min;
		else
			arr[i] -= y_min;
		i++;
	}
}

static int	*find_coordinates(const char **map)
{
	int	*array;
	int	count;
	int	row;
	int	col;

	array = (int *)malloc(sizeof(*array) * 8);
	if (array == NULL)
		exit(1);
	count = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '#')
			{
				array[count++] = row;
				array[count++] = col;
			}
			col++;
		}
		row++;
	}
	return (array);
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
		exit(2);
	i = 0;
	while (i < 4)
	{
		if (get_next_line(fd, &line) < 1 && i == 0)
			return (NULL);
		if (*line == '\0')
			exit(3);
		map[i++] = line;
	}
	get_next_line(fd, &line);
	if (*line != '\0')
	{
		free(line);
		exit(4);
	}
	map[i] = NULL;
	free(line);
	return (map);
}

static void	print_stuct(t_block *head)
{
	int	i;

	while(head != NULL)
	{
		i = 0;
		while (i < 8)
		{
			ft_putnbr((head->pos)[i]);
			i++;
		}
		ft_putchar('\n');
		head = head->next;
	}
}

void	validate(const int fd, t_block **head)
{
	char	**map;
	int		*pos;
	t_block	*temp;

	temp = block_new(NULL);
	*head = temp;
	while (1)
	{
		map = fill_map(fd);
		if (map == NULL)
			break ;
		print_map(map);
		if (validate_map((const char **) map) < 0)
			exit(5);
		if (validate_tetrimino((const char **) map) < 6)
			exit(6);
		pos = find_coordinates((const char **) map);
		top_left(pos);
		temp = block_new(pos);
		print_stuct(temp);
		temp = temp->next;
//		free(pos);
		free_map(map);
	}
//	print_stuct(*head);
}
