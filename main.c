/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:59:23 by altikka           #+#    #+#             */
/*   Updated: 2022/02/01 18:24:55 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int	error_handle(void)
{
	ft_putendl("error");
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		**map;
	size_t	size;

	if (argc != 2 && error_handle())
		return (-1);
	fd = open(argv[1], O_RDWR);
	if (fd == -1 && error_handle())
		return (-1);
	map = NULL;
	size = 0;
	fillit(fd, &map, size);
	if (close(fd) == -1 && error_handle())
		return (-1);
//	ft_putendl("----BEFORE SHUTTING DOWN MAIN.C----");
//	system("leaks fillit");
	return (0);
}
