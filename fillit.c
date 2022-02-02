/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/02/02 15:10:17 by altikka          ###   ########.fr       */
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
	if (ret == -1)
	{
		ft_putendl("error");
		exit(664);
	}
	head = block_new((const int *) pos);
	if (head == NULL)
	{
		ft_memdel((void **) &pos);
		ft_putendl("error");
		exit(665);
	}
	ft_memdel((void **) &pos);
	count = 1;
	while (ret != 0)
	{
		if (count >= 26)
		{
			free_blocks(&head);
			ft_putendl("error");
			exit(666);
		}
		ret = lost_and_found(fd, &pos);
		if (ret == -1)
		{
			ft_memdel((void **) &pos);
			free_blocks(&head);
			ft_putendl("error");
			exit(667);
		}
		if (block_append(&head, (const int *) pos) == -1)
		{
			ft_memdel((void **) &pos);
			free_blocks(&head);
			ft_putendl("error");
			exit(668);
		}
		ft_memdel((void **) &pos);
		count++;
	}
	block_ordinal(&head);
	size = map_min_size(head);
	(*map) = create_map(size);
	if (*map == NULL)
	{
		free_blocks(&head);
		ft_putendl("error");
		exit(669);
	}
	solver(head, map, &size);
	print_result(*map, size);
	free_map((void **) *map, size);
	free_blocks(&head);
	return (0);
}
