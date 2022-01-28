/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/01/27 17:00:49 by emende           ###   ########.fr       */
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
//	print_int_array(pos);
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
//		print_int_array(pos);
		block_append(&head, (const int *) pos);
		free(pos);
		count++;
	}
	block_ordinal(&head);
//	print_struct(head);
	size = map_min_size(head);
	map = create_map(size);

//	print_result(map, size);
//	ft_putchar('\n');
	solver(head, &map, &size);
//	ft_putendl("----AFTER EXITING SOLVER.C----");	//
//	system("leaks fillit");							//
	print_result(map, size);

	free_map((void **) map, size);				//////
	free_blocks(&head);
	return (0);
}
