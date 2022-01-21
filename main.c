/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:59:23 by altikka           #+#    #+#             */
/*   Updated: 2022/01/21 16:35:47 by altikka          ###   ########.fr       */
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
	int	fd;

	if (argc != 2 && error_handle())
		return (-1);
	fd = open(argv[1], O_RDWR);
	if (fd == -1 && error_handle())
		return (-1);
	fillit(fd);
	if (close(fd) == -1 && error_handle())
		return (-1);
	system("leaks fillit");
	return (0);
}
