/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:43:17 by altikka           #+#    #+#             */
/*   Updated: 2022/01/12 16:33:02 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	buffer_to_line(char **line, char *buf)
{
	char	*join;

	join = ft_strjoin(*line, buf);
	ft_strdel(line);
	*line = join;
}

static int	read_buffer(int const fd, char **line, char **arr)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	ft_bzero(buf, BUFF_SIZE + 1);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		temp = ft_strchr(buf, '\n');
		if (temp != NULL)
		{
			temp[0] = '\0';
			buffer_to_line(line, buf);
			temp++;
			arr[fd] = ft_strdup(temp);
			return (1);
		}
		buffer_to_line(line, buf);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (*line == NULL || *line[0] == '\0')
		return (0);
	return (1);
}

static int	check_array(int const fd, char **line, char **arr)
{
	char	*temp;
	char	*next;

	if (arr[fd] == NULL)
		return (read_buffer(fd, line, arr));
	temp = ft_strchr(arr[fd], '\n');
	if (temp == NULL)
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
		return (read_buffer(fd, line, arr));
	}
	*line = ft_strndup(arr[fd], (size_t)(temp - arr[fd]));
	temp++;
	next = ft_strdup(temp);
	ft_strdel(&arr[fd]);
	arr[fd] = next;
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char	*arr[FD_SIZE];

	if (read(fd, arr[0], 0) < 0)
		return (-1);
	if (fd < 0 || fd >= FD_SIZE || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	return (check_array(fd, line, arr));
}
