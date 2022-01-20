/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_set_attributes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:19:40 by altikka           #+#    #+#             */
/*   Updated: 2022/01/20 16:00:13 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	block_set_attributes(t_block **head)
{
	t_block	*temp;
	size_t	n;
	size_t	i;

	temp = *head;
	n = 1;
	while (temp)
	{
		i = 0;
		while (i < ARR_LEN)
		{
			if (i % 2 == 0 && temp->pos[i] >= temp->height)
				temp->height = (temp->pos)[i] + 1;
			else if (i % 2 != 0 && temp->pos[i] >= temp->width)
				temp->width = (temp->pos)[i] + 1;
			i++;
		}
		temp->n = n;
		temp = temp->next;
		n++;
	}
}
