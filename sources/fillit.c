/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & ememde <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/01/14 15:28:41 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	fillit(const int fd)
{
	int		res;
	char	*line;

	res = 1;
	while (res)
	{
		get_next_line(fd, &line);
		ft_putstr(line);
		free(line);
	}
	return (0);
}
