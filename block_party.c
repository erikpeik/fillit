/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_party.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende  <@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:37:10 by emende            #+#    #+#             */
/*   Updated: 2022/02/01 15:13:26 by altikka          ###   ########.fr       */
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

void	block_ordinal(t_block **head)
{
	t_block	*temp;
	int		n;

	temp = *head;
	n = 1;
	while (temp)
	{
		temp->n = n;
		temp = temp->next;
		n++;
	}
}

void	block_append(t_block **head, const int *pos)
{
	t_block	*temp;
	t_block	*new;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	new = block_new(pos);
	temp->next = new;
}

t_block	*block_new(const int *pos)
{
	t_block	*new;

	new = (t_block *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (pos == NULL)
	{
		new->pos = NULL;
	}
	else
	{
		new->pos = (int *)malloc(sizeof(int) * ARR_LEN);
		if (new->pos == NULL)
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->pos, pos, (sizeof(int) * ARR_LEN));
	}
	new->width = 0;
	new->height = 0;
	new->n = 0;
	new->next = NULL;
	return (new);
}
