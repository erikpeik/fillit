/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/02/01 15:37:33 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	fillit(const int fd)
{
	int		*pos;
	t_block	*head;
	size_t	count;
	size_t	size;
	int		**map;

	pos = lost_and_found(fd);
	head = block_new((const int *) pos);
	free(pos);
	count = 1;
	while (count)
	{
		if (count > 26)
			exit(0);
		pos = lost_and_found(fd);
		if (pos == NULL)
			break ;
		block_append(&head, (const int *) pos);
		free(pos);
		count++;
	}
	block_ordinal(&head);
	size = map_min_size(head);
	map = create_map(size);
	solver(head, &map, &size);
	print_result(map, size);
	free_map((void **) map, size);
	free_blocks(&head);
	return (0);
}
