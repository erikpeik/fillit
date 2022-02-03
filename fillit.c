/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/02/02 17:34:34 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void	get_blocks(const int fd, t_block **head)
{
	int	*pos;
	int	ret;
	int	count;

	pos = NULL;
	ret = lost_and_found(fd, &pos);
	if (ret == -1 && err_exit())
	{
		system("leaks fillit");
		exit(1);
	}
	*head = block_new((const int *) pos);
	if (*head == NULL && err_pos(pos))
	{
		system("leaks fillit");
		exit(1);
	}
	ft_memdel((void **) &pos);
	count = 1;
	while (ret != 0)
	{
		if (count >= 26 && err_blocks(*head))
		{
			system("leaks fillit");
			exit(1);
		}
		ret = lost_and_found(fd, &pos);
		if (ret == -1 && err_all(pos, *head))
		{
			system("leaks fillit");
			exit(1);
		}
		if (block_append(head, (const int *) pos) == -1 && err_all(pos, *head))
		{
			system("leaks fillit");
			exit(1);
		}
		ft_memdel((void **) &pos);
		count++;
	}
}

int	fillit(const int fd, int ***map, size_t size)
{
	t_block	*head;

	get_blocks(fd, &head);
	block_ordinal(&head);
	size = map_min_size(head);
	(*map) = create_map(size);
	if (*map == NULL && err_blocks(head))
	{
		system("leaks fillit");
		exit(1);
	}
	solver(head, map, &size, 0);
	print_result(*map, size);
	free_map((void **) *map, size);
	free_blocks(&head);
	return (0);
}
