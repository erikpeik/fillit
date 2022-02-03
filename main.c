/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:59:23 by altikka           #+#    #+#             */
/*   Updated: 2022/02/03 13:58:31 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		**map;
	size_t	size;

	if (argc != 2 && err_exit())
		return (-1);
	fd = open(argv[1], O_RDWR);
	if (fd == -1 && err_exit())
		return (-1);
	map = NULL;
	size = 0;
	fillit(fd, &map, size);
	if (close(fd) == -1 && err_exit())
		return (-1);
	return (0);
}
