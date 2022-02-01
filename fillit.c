/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/02/01 19:36:01 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	fillit(const int fd, int ***map, size_t size)
{
	int		*pos;
	int		ret;
	t_block	*head;
	size_t	count;

	pos = NULL;
	ret = lost_and_found(fd, &pos);
	head = block_new((const int *) pos);
	ft_memdel((void **) &pos);
	count = 1;
	while (count)
	{
		if (count > 26)
			exit(0);
		ret = lost_and_found(fd, &pos);
		if (ret == -1)
		{
			ft_putendl("error");
			exit(4444);
		}
		if (ret == 0)
			break ;
		block_append(&head, (const int *) pos);
		ft_memdel((void **) &pos);
		count++;
	}
	block_ordinal(&head);
	size = map_min_size(head);
	(*map) = create_map(size);
	solver(head, map, &size);
	print_result(*map, size);
	free_map((void **) *map, size);
	free_blocks(&head);
	return (0);
}
