/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/01/24 14:02:17 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	free_blocks(t_block **abl)
{
	if ((*abl)->next != NULL)
		free_blocks(&(*abl)->next);
	free((*abl)->pos);
	free(*abl);
}

int	fillit(const int fd)
{
	int		*pos;
	t_block	*head;
	size_t	count;

	pos = lost_and_found(fd);
	print_int_array(pos);
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
		print_int_array(pos);
		block_append(&head, (const int *) pos);
		free(pos);
		count++;
	}
	block_set_attributes(&head);
	print_struct(head);
	free_blocks(&head);
	return (0);
}
